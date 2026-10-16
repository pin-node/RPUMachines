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
you. Positions only: never add the picture or any artwork.

**Physics (optional):** your game fires coils; the real machine then moves the ball or the targets,
and switches change. A simulator has no ball, so `physics/<machine>.sim` tells it, coil by coil,
using the header's names (see the Star Trek file):

```
# The outhole kicker serves the ball: it leaves the outhole
physics SOL_OUTHOLE opens SW_OUTHOLE
# A coil can close switches too, e.g. a ball served onto a shooter-lane switch
physics SOL_OUTHOLE opens SW_OUTHOLE closes SW_SHOOTER_LANE
# Where the ball rests at power-on
close SW_OUTHOLE
```

A machine with a ball trough (several balls) describes the trough instead, and the simulator counts
the balls: its switches from the exit end, the coil that serves, the coil that feeds it from the
outhole, and how many balls it holds at power-on (see the Scorpion file, and rpu-sim's README):

```
trough SW_BALL_1 SW_BALL_2 serve SOL_BALL_RAMP_THROWER feed SOL_OUTHOLE from SW_OUTHOLE balls 2
```

**Never include ROM data**: no dumps, no bytes copied from a ROM. Numbers and names from manuals and
schematics only.
