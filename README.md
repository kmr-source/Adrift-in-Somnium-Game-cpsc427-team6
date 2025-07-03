## Dungeon crawler turn-based window game

1. AI randomized movements from the monsters
2. Turn based game
3. psuedo-randomly generated maps to explore
4. 5 unique enemies + 2 boss fights (using AI randomized movement based on A* search algorithm
5. 23 different artifacts with unique effects
6. randomly generated equipment for the hero
7. Window based game
8. openGl (C), C++
9. Game data is saved by coverting data generated into json files.
10. Json files are then read the reloaded back, when the game restarts 

# Adrift in Somnium

## Synopsis
Overworked player wakes up in the game world and the purpose is to fight off monsters. This is a narrative-driven game built using modern C++ and OpenGL. The game blends interactive storytelling with a 2D/3D graphics engine and features custom rendering, input, and audio systems.

## 🚀 Features

- Written in **C++14**
- OpenGL-based rendering with custom shaders
- Windows & Linux
- Input handling via **GLFW** and **SDL2**
- Audio playback via **SDL2_mixer**
- Font rendering using **FreeType**
- Uses **GLM** for linear algebra and **STB Image** for texture loading
- XML support with **RapidXML**

---

## 🧰 Dependencies

The following libraries are required (some provided in `ext/`):

| Library       | Usage                   |
| ------------- | ------------------------|
| GLFW          | Window/context/input    |
| SDL2          | Input & platform APIs   |
| SDL2_mixer    | Audio playback          |
| OpenGL        | Graphics rendering      |
| GL3W          | OpenGL extension loading|
| GLM           | Math library            |
| FreeType      | Font rendering          |
| STB Image     | Texture loading         |
| RapidXML      | XML parsing             |

---

## 🛠 Build Instructions

### Prerequisites

- CMake ≥ 3.1
- C++14-compatible compiler
- OpenGL development libraries

### Linux/macOS

```bash
mkdir build
cd build
cmake ..
make
./adrift_in_somnium





