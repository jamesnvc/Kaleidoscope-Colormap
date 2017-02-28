/* -*- mode: c++ -*-
 * Kaleidoscope-Colormap -- Per-layer colormap effect
 * Copyright (C) 2016, 2017  Gergely Nagy
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

#include <Kaleidoscope-Colormap.h>

#include <avr/pgmspace.h>

namespace KaleidoscopePlugins {

  void
  Colormapper::update (void) {
    for (uint8_t l = 0; l < 32; l++) {
      if (!Layer.isOn (l))
        continue;

      for (uint8_t r = 0; r < ROWS; r++) {
        for (uint8_t c = 0; c < COLS; c++) {
          cRGB color;

          if (!lookupColor (l, r, c, &color))
            continue;

          LEDControl.led_set_crgb_at (r, c, color);
        }
      }
    }
  }

  const cRGB *ColormapEffect::palette;
  const uint8_t *ColormapEffect::colorMap;

  ColormapEffect::ColormapEffect (void) {
  }

  void
  ColormapEffect::configure (const cRGB _palette[], const uint8_t _colorMap[][ROWS][COLS]) {
    palette = _palette;
    colorMap = (const uint8_t *)_colorMap;
  }

  const bool
  ColormapEffect::lookupColor (uint8_t layer, uint8_t row, uint8_t column, cRGB *color) {
    uint8_t colorIndex;

    uint16_t mapIndex = (layer * ROWS * COLS + row * COLS + column);
    colorIndex = pgm_read_byte (&(colorMap[mapIndex]));

    if (colorIndex == Transparent)
      return false;

    color->b = pgm_read_byte (&(palette[colorIndex].b));
    color->g = pgm_read_byte (&(palette[colorIndex].g));
    color->r = pgm_read_byte (&(palette[colorIndex].r));

    return true;
  }

};

KaleidoscopePlugins::ColormapEffect ColormapEffect;
