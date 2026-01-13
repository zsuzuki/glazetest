# Glaze sample

This is a minimal sample showing reflection-style mapping with the
[glaze](https://github.com/stephenberry/glaze) JSON library.
The project targets C++23 to enable Glaze's aggregate reflection.

## Build

```sh
cmake -S . -B build
cmake --build build
./build/glaze_sample
```

Note: the first configure will fetch `glaze` via `FetchContent`.
