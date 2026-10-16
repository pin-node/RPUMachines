# Adding a machine

Thanks for helping. One pull request per machine.

1. **Header:** copy any header in `src/` to `src/<Maker><Title><Year>.h`. Keep its layout: `LAMP_…`, `SW_…` and `SOL_…` defines with the RPU
   OS's numbers, and `SolenoidAssociatedSwitches[]` for bumpers and slingshots where the RPU OS fires
   them (Bally, Stern). Williams System 3-7 fire them in hardware: leave the table out. Change the include guard.
2. **Names:** copy any file in `names/` to `names/<maker>-<title>-<year>.json`. Fill in:
   - `machine`: maker, title, year and game number;
   - `header`: your header's file name;
   - `sources`: the documents you read the names from (manual pages, schematic numbers);
   - one `{"n": …, "name": …}` line for every lamp, switch and solenoid your header defines.

   Use the manufacturer's names, from its own documents, up to 40 characters. Add a location in
   parentheses where the name alone doesn't say where it is. What a lamp means in one game's rules
   belongs in that game, not here.
3. **List it:** add the header to `includes=` in `library.properties`, and a row to the table in
   `README.md`.
4. **Check:** `python3 tools/check.py --fix` (Python 3.9 or newer). It must print OK for your
   machine. The same check runs on your pull request.
5. If you can, build a game against it: say which one in the pull request.

**Layouts (optional):** use [rpu-sim](https://github.com/wifijt/rpu-sim): run your game with a picture of
the playfield (`./play.py MyGame --image playfield.jpg`), line the picture up, then in **Edit
layout** drag each switch, coil and lamp from the lists onto its spot, and **Save layout**. If a
Visual Pinball table exists for the machine, `tools/vpx_import.py` in rpu-sim places most lamps for
you. Add `physics` and `ballStarts` (see the Star Trek layout) so a simulator can serve the ball.
Positions only: never add the picture or any artwork.

**Never include ROM data**: no dumps, no bytes copied from a ROM. Numbers and names from manuals and
schematics only.
