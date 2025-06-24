# cub3D

A Wolfenstein-style 3D raycasting engine written in C.

---

## Table of Contents

* [Features](#features)
* [Building](#building)
* [Running](#running)
* [Controls](#controls)
* [Map File Format](#map-file-format)
* [Project Structure](#project-structure)
* [Group Project](#group-project)


---

## Features

* Parse `.cub` configuration files for textures, colors, and map layout.
* Render textured walls, floors, and sprites using classic raycasting.
* Smooth player movement and rotation.
* Sliding doors with smooth open/close animations.
* Player-centered minimap with real-time door animations and sprite indicators.

## Building

```sh
# Clone the repo
git clone https://github.com/lanfeitiao/cub3D.git
cd cub3D

# Compile
make
```

This will produce the executable `cub3D` in the project root.

## Running

```sh
# Run with one of the example maps:
./cub3D map/good/test.cub

# You can also pass your own .cub file:
./cub3D path/to/your_map.cub
```

If you pass an invalid file or the map is malformed, the program will print an error and exit.

## Controls

| Key            | Action                 |
| -------------- | ---------------------- |
| `W`            | Move forward           |
| `S`            | Move backward          |
| `A`            | Move left              |
| `D`            | Move right             |
| ← / →          | Rotate view left/right |
| `Space`        | Open/close door        |
| `ESC`          | Quit the program       |

## Map File Format

A valid `.cub` file consists of:

1. **Texture paths** (north, south, west, east, door, sprite)

   ```txt
   NO ./textures/north_texture.png
   SO ./textures/west_texture.png
   WE ./textures/south_texture.png
   EA ./textures/east_texture.png
   DOOR ./textures/door_texture.png
    
   ANIMATED ./textures/tree/tree00.png
   ANIMATED ./textures/tree/tree01.png
   ANIMATED ./textures/tree/tree02.png
   ANIMATED ./textures/tree/tree03.png
   ANIMATED ./textures/tree/tree04.png
   ANIMATED ./textures/tree/tree05.png
   ```
2. **Floor and ceiling colors**

   ```txt
   F 220,100,0
   C 225,30,0
   ```
3. **Map layout** using integers and letters (`1`=wall, `0`=empty, `N/S/E/W`=player start + facing, `D`=door, `A`=animated sprite)

   ```txt
   111111111111   
   10101001A001
   1110110D0N01
   101011010001
   111011111011
   ```
For full examples, see the `.cub` files in the `map/` directory.

## Project Structure

```
.
├── Makefile           # build rules
├── README.md          # this documentation
├── .gitignore
├── include/           # header files
│   ├── cub3d.h
│   └── ...
├── lib/               # MLX42 + libft
├── src/               # core raycasting & parsing code
├── map/               # example .cub files
├── textures/          # wall & door & sprite textures
└── cub3D              # generated executable (after `make`)
```
## Group Project

This repository is a collaborative project by me and **[seungah](https://github.com/seungahpyun)**.

