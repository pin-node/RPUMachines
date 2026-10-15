# RPUMachines

Machine definitions for RetroPinUpgrade (RPU) games. Each machine has:

- a header, `src/<Machine>.h`, with its lamp, switch and solenoid numbers, shared by every game
  written for that machine;
- a names file, `names/<machine>.json`, with the manufacturer's name for each one, so tools can
  label test screens and logs ("Lamp 42 · Same player shoots again").

| Machine | Header | Names |
|---|---|---|
| Bally Star Trek (1979) | `src/BallyStarTrek1979.h` | `names/bally-star-trek-1979.json` |
| Williams Scorpion (1980) | `src/WilliamsScorpion1980.h` | `names/williams-scorpion-1980.json` |

Some machines also have a **layout**, `layouts/<machine>.json`: where each lamp, switch and coil sits
on the playfield, as fractions of its width and height, and which page of the manual has the
playfield drawing. Simulators and lamp tools use it (rpu-sim draws the playfield from it). The
manual itself is never stored here: tools render the page from your own copy.

**Add yours:** see [CONTRIBUTING.md](CONTRIBUTING.md).

## Install

Arduino IDE: **Tools → Manage Libraries…**, search **RPUMachines**, and click **Install**.

arduino-cli: `arduino-cli lib install RPUMachines`.

## Use

Include the machine's header after `RPU_Config.h` and `RPU.h`, from the sketch (`.ino`) only:

```cpp
#include "RPU_Config.h"
#include "RPU.h"
#include <BallyStarTrek1979.h>
```

The header defines `LAMP_…`, `SW_…` and `SOL_…` numbers (the RPU OS's own indices), and
`SolenoidAssociatedSwitches[]`, the switch-to-coil table for the bumpers and slingshots that
`RPU_SetupGameSwitches()` takes.

## Credits

For **RetroPinUpgrade (RPU)** games: RPU is Dick Hamill's
([github.com/RetroPinUpgrade](https://github.com/RetroPinUpgrade)). The Scorpion's numbers come from
his Scorpion2022; the Star Trek's were checked against Dave's Think Tank's
[Star Trek 2025](https://github.com/DavesThinkTank/Bally-Star-Trek).

## Licence

GPL-3.0, as the RPU OS and its games are. See `LICENSE`. Contributions come in under the same
licence.

Machine names are trademarks of their owners and are used only to identify the machine each
definition describes. RPUMachines isn't affiliated with or endorsed by them.
