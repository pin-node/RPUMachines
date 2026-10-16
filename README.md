# RPUMachines

Machine definitions for RetroPinUpgrade (RPU) games: one set of files per machine, shared by every
game and tool written for it.

| File | What it holds | Who uses it |
|---|---|---|
| `src/<Machine>.h` | Lamp, switch and coil numbers (`LAMP_…`, `SW_…`, `SOL_…`) | Your game's code |
| `names/<machine>.json` | The manufacturer's name for each lamp, switch and coil | Test screens, logs, simulators |
| `layouts/<machine>.json` (optional) | Where each lamp, switch and coil sits on the playfield | Simulators ([rpu-sim](https://github.com/wifijt/rpu-sim)), lamp tools |
| `physics/<machine>.sim` (optional) | What the playfield does when a coil fires: which switches it opens or closes (the outhole kicker serves the ball, so the outhole switch opens), and where the ball rests at power-on | Simulators |

| Machine | Header | Names | Layout | Physics |
|---|---|---|---|---|
| Bally Star Trek (1979) | `src/BallyStarTrek1979.h` | ✓ | ✓ | ✓ |
| Williams Scorpion (1980) | `src/WilliamsScorpion1980.h` | ✓ | – | ✓ |

Positions in a layout are fractions of the playfield's width and height, from its top-left corner.
Layouts hold positions only: never artwork, photos or manual pages.

**Add a machine:** see [CONTRIBUTING.md](CONTRIBUTING.md). Every pull request is checked by
`tools/check.py`.

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
