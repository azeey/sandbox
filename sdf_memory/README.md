# Memory profiling of libsdformat

This was developed in conjunction with https://github.com/gazebosim/sdformat/pull/1589 to test improvements in the load time and memory consumption of libsdformat.

## Prerequisites

- `mimalloc`
  Ubuntu: `sudo apt install libmimalloc-dev`
  Homebrew: `brew install mimalloc`

## Build and run

```bash
cmake -S . -B build
cmake --build build
MIMALLOC_SHOW_STATS=1 build/sdf_memory 3k_shapes.sdf
```

