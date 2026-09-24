# Viewinator

A lightweight PPM image viewer built in C++ with SDL2.

## Features
- Manually parses the PPM file header and raw binary pixel data (no image libraries used)
- Renders images pixel-by-pixel using low-level SDL surface manipulation
- Toggle between **color** and **grayscale** rendering (grayscale computed via weighted RGB luminance: `0.299R + 0.587G + 0.114B`)

## Requirements
- SDL2 (`sudo apt-get install libsdl2-dev` on Ubuntu)

## Build
```bash
g++ -o viewinator img_viewer.cpp `sdl2-config --cflags --libs`
```

## Usage
```bash
./viewinator
```
- Enter the path to a `.ppm` file when prompted
- Choose `1` for grayscale or `2` for color

## Notes
Works with PPM (P6) images only.

**Inspo** - https://youtu.be/sItRLFjbqvo?si=TcFuB1qDa9W3rm1V
**Set** - https://youtu.be/lsduGj42ZJA?si=3fXHS3ele1lcuAeT
