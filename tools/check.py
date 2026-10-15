#!/usr/bin/env python3
"""Check every machine: its header and its names file agree, and both are complete.

    python3 tools/check.py          # check; exits 1 on any problem
    python3 tools/check.py --fix    # also rewrite names/*.json in the standard layout

Runs on every pull request. For each names/<machine>.json:
- machine, header and sources are filled in;
- every lamp, switch and solenoid has a whole number and a name of 1 to 40 characters, no repeats;
- every LAMP_, SW_ and SOL_ number the header defines has a name, and every name has a define;
- the header is listed in library.properties' includes= and in the README's machine table.
"""
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
KINDS = (("lamps", "LAMP_"), ("switches", "SW_"), ("solenoids", "SOL_"))
NAME_MAX = 40          # the PinNode manifest's limit for a lamp, switch or coil name


def header_numbers(header: Path) -> dict:
    text = header.read_text()
    return {kind: {int(v) for v in re.findall(r"^\s*#define\s+" + prefix + r"\w+\s+(\d+)\b", text, re.M)}
            for kind, prefix in KINDS}


def layout(d: dict) -> str:
    """One entry per line, so a pull request's diff shows exactly which names changed."""
    out = ["{"]
    keys = list(d)
    for i, k in enumerate(keys):
        comma = "," if i < len(keys) - 1 else ""
        v = d[k]
        if isinstance(v, list):
            out.append(f' "{k}": [')
            out += ["  " + json.dumps(e, ensure_ascii=False) + ("," if j < len(v) - 1 else "") for j, e in enumerate(v)]
            out.append(" ]" + comma)
        else:
            out.append(f' "{k}": {json.dumps(v, ensure_ascii=False)}{comma}')
    return "\n".join(out + ["}"]) + "\n"


def check(path: Path, includes: set, readme: str, fix: bool) -> list:
    problems = []
    try:
        d = json.loads(path.read_text())
    except json.JSONDecodeError as e:
        return [f"not valid JSON: {e}"]
    for field in ("machine", "header"):
        if not isinstance(d.get(field), str) or not d[field].strip():
            problems.append(f'"{field}" is missing')
    if not isinstance(d.get("sources"), list) or not all(isinstance(s, str) and s.strip() for s in d["sources"]) \
            or not d.get("sources"):
        problems.append('"sources" must list the documents the names were read from')
    header = ROOT / "src" / str(d.get("header", ""))
    defined = header_numbers(header) if d.get("header") and header.is_file() else None
    if d.get("header") and defined is None:
        problems.append(f"src/{d['header']} doesn't exist")
    if d.get("header") and d["header"] not in includes:
        problems.append(f"{d['header']} isn't in library.properties includes=")
    if d.get("header") and f"`src/{d['header']}`" not in readme:
        problems.append(f"{d['header']} has no row in the README's machine table")
    for kind, _ in KINDS:
        entries = d.get(kind)
        if not isinstance(entries, list):
            problems.append(f'"{kind}" must be a list')
            continue
        seen = set()
        for e in entries:
            n, name = (e.get("n"), e.get("name")) if isinstance(e, dict) else (None, None)
            if not isinstance(n, int) or isinstance(n, bool) or n < 0:
                problems.append(f"{kind}: {e} needs a whole number n")
                continue
            if not isinstance(name, str) or not name.strip() or len(name) > NAME_MAX:
                problems.append(f"{kind} {n}: the name must be 1 to {NAME_MAX} characters")
            if n in seen:
                problems.append(f"{kind} {n} is listed twice")
            seen.add(n)
        if defined is not None:
            problems += [f"{kind} {n} is defined in the header but has no name" for n in sorted(defined[kind] - seen)]
            problems += [f"{kind} {n} has a name but no define in the header" for n in sorted(seen - defined[kind])]
        if fix:
            d[kind] = sorted(entries, key=lambda e: e.get("n", 0) if isinstance(e, dict) else 0)
    if fix and not problems:
        path.write_text(layout(d))
    return problems


def main() -> None:
    fix = "--fix" in sys.argv[1:]
    props = (ROOT / "library.properties").read_text()
    includes = {s.strip() for s in re.search(r"^includes=(.*)$", props, re.M).group(1).split(",")}
    readme = (ROOT / "README.md").read_text()
    files = sorted((ROOT / "names").glob("*.json"))
    headers = {p.name for p in (ROOT / "src").glob("*.h")}
    named = set()
    total = 0
    for path in files:
        problems = check(path, includes, readme, fix)
        try:
            named.add(json.loads(path.read_text()).get("header"))
        except json.JSONDecodeError:
            pass
        for p in problems:
            print(f"names/{path.name}: {p}")
        total += len(problems)
        if not problems:
            print(f"names/{path.name}: OK")
    for h in sorted(headers - named):
        print(f"src/{h}: no names/ file names it")
        total += 1
    raise SystemExit(1 if total else 0)


if __name__ == "__main__":
    main()
