// Copyright MIT
#pragma once

// Factory default RGB matrix effect: ALPHAS_MODS (static two-tone, no motion).
// Letters use the base hue; modifiers use base hue + speed offset.
// Only applies to uninitialized EEPROM (fresh board / after EE_CLR).
// Your own effect choice from Settings (RM_NEXT/RM_PREV) persists afterwards.
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS
