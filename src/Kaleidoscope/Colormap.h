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

#pragma once

#include <Kaleidoscope-LEDControl.h>

namespace KaleidoscopePlugins {
  class ColormapEffect : public LEDMode {
  public:
    static const uint8_t Transparent = 255;

    ColormapEffect (void);

    void configure (const cRGB palette[], const uint8_t colorMap[][ROWS][COLS]);

    virtual void update (void) final;

  private:
    static const cRGB *palette;
    static const uint8_t *colorMap;
  };
};

extern KaleidoscopePlugins::ColormapEffect ColormapEffect;