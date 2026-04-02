#pragma once

/* Vial UID — must match existing firmware so EEPROM settings survive reflash */
#define VIAL_KEYBOARD_UID {0x79, 0xED, 0x40, 0xBB, 0x09, 0x8B, 0xC1, 0x9E}

/* Unlock combo: both outer thumb keys */
#define VIAL_UNLOCK_COMBO_ROWS {3, 3}
#define VIAL_UNLOCK_COMBO_COLS {2, 5}

#define QUICK_TAP_TERM 120
#define NUM_ENCODERS 1
#define DYNAMIC_KEYMAP_LAYER_COUNT 14
