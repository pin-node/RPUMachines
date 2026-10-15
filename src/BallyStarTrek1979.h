/**************************************************************************
 * Bally Star Trek (1979, AS-2518-35 MPU): lamps, switches and solenoids,
 * for RetroPinUpgrade (RPU) games.
 *
 * One definition for every game written for this machine. Install the
 * RPUMachines library and include this file after RPU_Config.h and RPU.h:
 *
 *     #include "RPU_Config.h"
 *     #include "RPU.h"
 *     #include <BallyStarTrek1979.h>
 *
 * The numbers are the RPU OS's: lamp, switch and solenoid indices as the
 * RPU_SetLampState / RPU_ReadSingleSwitchState / RPU_PushToSolenoidStack
 * calls take them. They were checked, one by one, against the same machine's
 * definitions in Dave's Think Tank's Star Trek 2025 (ST2025p09.h, GPL-3.0,
 * github.com/DavesThinkTank/Bally-Star-Trek): all 60 lamps, 34 switches and
 * 9 solenoids agree.
 *
 * The define names are those of the Star Trek 2022 game, kept so its code reads
 * as it did. Some describe that game's use rather than the part: lamps 22 and 23
 * (LAMP_R/L_UPPER_CHUTE_5K) and switches 24 and 25 (SW_LEFT/RIGHT_MIDDLE_LANE)
 * are Bally's left middle inside and outside lanes, and lamps 37 and 38
 * (LAMP_R/L_OUTER_LANE) are the outlane specials. For what each number is on
 * the machine, in Bally's own words, see names/bally-star-trek-1979.json
 * (tools/check.py checks it against this file).
 *
 * This file is free software under the GNU General Public License v3
 * (see LICENSE), as the RPU OS and the games it serves are.
 **************************************************************************/
#ifndef BALLY_STAR_TREK_1979_H
#define BALLY_STAR_TREK_1979_H

#define LAMP_BONUS_1K           0
#define LAMP_BONUS_2K           1
#define LAMP_BONUS_3K           2
#define LAMP_BONUS_4K           3
#define LAMP_BONUS_5K           4
#define LAMP_BONUS_6K           5
#define LAMP_BONUS_7K           6
#define LAMP_BONUS_8K           7
#define LAMP_BONUS_9K           8
#define LAMP_BONUS_10K          9
#define LAMP_BONUS_20K          10
#define LAMP_BONUS_3X           13 //and planet special
#define LAMP_BONUS_2X           14 //and planet 3x
#define LAMP_PLANET_2X          15
#define LAMP_HS_2K              16
#define LAMP_HS_4K              17
#define LAMP_HS_6K              18
#define LAMP_HS_8K              19
#define LAMP_HS_10K             20
#define LAMP_HS_EXTRA_BALL      21
#define LAMP_R_UPPER_CHUTE_5K       22
#define LAMP_L_UPPER_CHUTE_5K       23
#define LAMP_SAUCER_B               24
#define LAMP_SAUCER_A               25
#define LAMP_SAUCER_L               26
#define LAMP_SAUCER_2L              27
#define LAMP_SAUCER_Y               28
#define LAMP_3K_ADV_BONUS           29
#define LAMP_R_INNER_LANE           30
#define LAMP_L_INNER_LANE           31
#define LAMP_ROLLOVER_B             32
#define LAMP_ROLLOVER_A             33
#define LAMP_TARGET_L               34
#define LAMP_TARGET_2L              35
#define LAMP_TARGET_Y               36
#define LAMP_R_OUTER_LANE           37
#define LAMP_L_OUTER_LANE           38
#define LAMP_Y                      39
#define LAMP_HEAD_SHOOT_AGAIN       40
#define LAMP_HEAD_MATCH             41
#define LAMP_SHOOT_AGAIN            42
#define LAMP_BALL_IN_PLAY           43   // the 2022 code's name; on the machine it's the apron credit lamp
#define LAMP_APRON_CREDIT           43
#define LAMP_SPECIAL_10K            44
#define LAMP_SPECIAL_25K            45
#define LAMP_SPECIAL_50K            46
#define LAMP_SPECIAL                47
#define LAMP_HEAD_BALL_IN_PLAY      48
#define LAMP_HEAD_HIGH_SCORE        49
#define LAMP_HEAD_GAME_OVER         50
#define LAMP_HEAD_TILT              51
#define LAMP_B                      52
#define LAMP_A                      53
#define LAMP_L                      54
#define LAMP_2L                     55
#define LAMP_HEAD_1P                56
#define LAMP_HEAD_2P                57
#define LAMP_HEAD_3P                58
#define LAMP_HEAD_4P                59
// names the template's code uses
#define LAMP_HEAD_PLAYER_1_UP       LAMP_HEAD_1P
#define LAMP_HEAD_PLAYER_2_UP       LAMP_HEAD_2P
#define LAMP_HEAD_PLAYER_3_UP       LAMP_HEAD_3P
#define LAMP_HEAD_PLAYER_4_UP       LAMP_HEAD_4P


#define SW_DROP_1                   0
#define SW_DROP_2                   1
#define SW_DROP_3                   2
#define SW_DROP_4                   3
#define SW_BALL_RETURN              4    // the shooter lane switch: the ball passing back into the lane
#define SW_SHOOTER_LANE             4
#define SW_CREDIT_RESET             5
#define SW_TILT                     6
// Star Trek has one tilt switch line; the template's handler asks for the plumb tilt
#define SW_PLUMB_TILT               SW_TILT
#define SW_OUTHOLE                  7
#define SW_COIN_3                   8
#define SW_COIN_1                   9
#define SW_COIN_2                   10
#define SW_SLAM                     15
#define SW_LOWER_HS_ROLLOVER        17
#define SW_RIGHT_INNNER_LANE        18
#define SW_LEFT_INNNER_LANE         19
#define SW_UPPER_500_TARGET         20
#define SW_UPPER_HS_ROLLOVER        21
#define SW_ADV_BONUS_BUMPERS        22
#define SW_3K_TARGET                23
#define SW_LEFT_MIDDLE_LANE         24
#define SW_RIGHT_MIDDLE_LANE        25
#define SW_Y_TARGET                 26
#define SW_2L_TARGET                27
#define SW_L_TARGET                 28
#define SW_A_ROLLOVER               29
#define SW_B_ROLLOVER               30
#define SW_SAUCER                   31
#define SW_RIGHT_OUTLANE            33
#define SW_LEFT_OUTLANE             34
#define SW_RIGHT_SLINGSHOT          35
#define SW_LEFT_SLINGSHOT           36
#define SW_CENTER_BUMPER            37
#define SW_RIGHT_BUMPER             38
#define SW_LEFT_BUMPER              39

#define SOL_KNOCKER                 5
#define SOL_OUTHOLE                 6
// The outhole kicker puts the ball straight back in the shooter lane (no trough)
#define SOL_SERVE_BALL              SOL_OUTHOLE
#define SOL_SAUCER                  7
#define SOL_LEFT_BUMPER            8
#define SOL_RIGHT_BUMPER             9
#define SOL_CENTER_BUMPER           10
#define SOL_LEFT_SLINGSHOT          11
#define SOL_RIGHT_SLINGSHOT         12
#define SOL_DROP_TARGET_RESET       13


//#define SOL_NONE          15

#define SOLCONT_FLIPPERS      0x80
#define SOLCONT_COIN_LOCKOUT  0x01

#define NUM_SWITCHES_WITH_TRIGGERS          5
#define NUM_PRIORITY_SWITCHES_WITH_TRIGGERS 5

struct PlayfieldAndCabinetSwitch SolenoidAssociatedSwitches[] = {
  { SW_RIGHT_SLINGSHOT, SOL_RIGHT_SLINGSHOT, 4},
  { SW_LEFT_SLINGSHOT, SOL_LEFT_SLINGSHOT, 4},
  { SW_LEFT_BUMPER, SOL_LEFT_BUMPER, 3},
  { SW_CENTER_BUMPER, SOL_CENTER_BUMPER, 3},
  { SW_RIGHT_BUMPER, SOL_RIGHT_BUMPER, 3}
};

#endif
