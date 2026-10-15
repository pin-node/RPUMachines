# RPUMachines

Machine definitions for RetroPinUpgrade (RPU) games. Each machine has:

- a header, `src/<Machine>.h`, with its lamp, switch and solenoid numbers, shared by every game
  written for that machine;
- a names file, `names/<machine>.json`, with the manufacturer's name for each one. PinNode's
  converter and app use these ("Lamp 42 · Same player shoots again").

| Machine | Header | Names |
|---|---|---|
| Bally Star Trek (1979) | `src/BallyStarTrek1979.h` | `names/bally-star-trek-1979.json` |
| Williams Scorpion (1980) | `src/WilliamsScorpion1980.h` | `names/williams-scorpion-1980.json` |

**Add yours:** see [CONTRIBUTING.md](CONTRIBUTING.md).

## Install

Arduino IDE: on **[github.com/pin-node/RPUMachines](https://github.com/pin-node/RPUMachines)**, click
**Code → Download ZIP**, then **Sketch → Include Library → Add .ZIP Library…** and pick that ZIP.

arduino-cli: `arduino-cli lib install --git-url https://github.com/pin-node/RPUMachines.git` (needs
`library.enable_unsafe_install`).

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

## Licence

GPL-3.0, as the RPU OS and its games are. See `LICENSE`. Contributions come in under the same
licence.
