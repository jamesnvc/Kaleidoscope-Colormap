# Kaleidoscope-Colormap

![status][st:stable] [![Build Status][travis:image]][travis:status]

 [travis:image]: https://travis-ci.org/keyboardio/Kaleidoscope-Colormap.svg?branch=master
 [travis:status]: https://travis-ci.org/keyboardio/Kaleidoscope-Colormap

 [st:stable]: https://img.shields.io/badge/stable-✔-black.png?style=flat&colorA=44cc11&colorB=494e52
 [st:broken]: https://img.shields.io/badge/broken-X-black.png?style=flat&colorA=e05d44&colorB=494e52
 [st:experimental]: https://img.shields.io/badge/experimental----black.png?style=flat&colorA=dfb317&colorB=494e52

The `ColorMap` extension provides an easier way to set up a different - static -
color map per-layer. This means that we can set up a map of colors for each key,
on a per-layer basis, and whenever a layer becomes active, the color map for
that layer is applied on top of everything else. The extension supports
transparent colors, to make things easier.

To save precious space, the extension uses a palette, limited to 255 colors (one
reserved for transparency).

## Using the extension

To set up a colormap, include the header, create a palette, and a colormap
description, and let the extension know that it shall use both of these:

```c++
#include <Kaleidoscope.h>
#include <Kaleidoscope-Colormap.h>

static const cRGB palette[] PROGMEM = {
  {0, 0, 0},
  {0xff, 0xff, 0xff},
};

static const uint8_t colormap[KEYMAP_SIZE][ROWS][COLS] PROGMEM = {
  [0] = KEYMAP_STACKED ( ... )
};

void setup (void) {
  Colormap.configure (palette, colormap);

  Kaleidoscope.setup (KEYMAP_SIZE);
  Kaleidoscope.use (&Colormap, NULL);
}
``` 

The palette is just an array of RGB colors, stored in `PROGMEM`. The index of
each entry will be used in the colormap itself.

The colormap should be specified very similarly to a keymap, except it contains
palette indexes instead of keys. But similar to the palette, it should reside in
`PROGMEM` too. It should be the same size as the keymap itself, otherwise the
firmware may randomly crash. It is recommended to use the `KEYMAP_SIZE` macro to
make sure the colormap is the right size.

To use the transparent color, use either
`KaleidoscopePlugins::ColormapEffect::Transparent` as the color index, or `255`.

## Extension methods

The extension provides a `Colormap` singleton object, with a single method:

### `.configure(palette, colormap)`

> Tells the extension to use the given palette and colormap.

## Further reading

Starting from the [example][plugin:example] is the recommended way of getting
started with the plugin.

 [plugin:example]: https://github.com/keyboardio/Kaleidoscope-Colormap/blob/master/examples/Colormap/Colormap.ino
