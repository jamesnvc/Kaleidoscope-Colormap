/* -*- mode: c++ -*-
 * Kaleidoscope-EEPROM-Colormap -- Per-layer colormap effect
 * Copyright (C) 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Kaleidoscope-LEDControl.h>

namespace KaleidoscopePlugins {
  class EEPROMColormapEffect : public LEDMode {
  public:
    static const uint8_t Transparent = 15;

    EEPROMColormapEffect (void);

    virtual void update (void) final;
    void configure (uint8_t maxLayers);

    virtual const bool lookupColor (uint8_t layer, uint8_t row, uint8_t column, cRGB *color) final;
    static bool focusHook (const char *command);

  private:
    static uint8_t maxLayers;
    static uint16_t paletteBase;
    static uint16_t mapBase;
  };
};

extern KaleidoscopePlugins::EEPROMColormapEffect EEPROMColormapEffect;

#define FOCUS_HOOK_COLORMAP FOCUS_HOOK(EEPROMColormapEffect.focusHook,   \
                                       "colormap.palette [<R G B>...]\n" \
                                       "-----------------------------\n" \
                                       "Display or set the palette. Limited to 15 colors.\n\n" \
                                       "colormap.map [index ...]\n"      \
                                       "------------------------\n"      \
                                       "Display or set the color map.")