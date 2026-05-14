# Tug-o'-Trivia

A two-player trivia game with a tug-of-war twist, built for the Ohio State University Proteus / SDP Simulator.

## About

Two players compete head-to-head, answering multiple-choice trivia questions across three themes:

- **FEH** — questions about OSU's Fundamentals of Engineering for Honors program
- **Geography** — world geography trivia
- **OSU** — Ohio State University history and culture

Each correct answer pulls a rope toward that player's side. The first player to pull the rope all the way wins. The game tracks per-player stats — correct/wrong answers and average response time — across rounds.

## Play it

1. Download the latest release from the [Releases page](https://github.com/HarshaKalivarapu/Tug-o-Trivia/releases).
2. Unzip the folder.
3. Double-click `game.exe`.

Windows may show a SmartScreen warning the first time you run an unsigned executable. Click *More info → Run anyway*.

## Build from source

Requires Windows and the OSU Proteus toolchain.

1. Install the [Proteus Dependency Installer](https://u.osu.edu/fehproteus/) for Windows. This sets up MinGW (`g++` and `mingw32-make`).
2. Restart your computer so the toolchain is picked up.
3. From the project root:

   ```
   mingw32-make
   .\game.exe
   ```

The Makefile automatically clones OSU's `simulator_libraries` repo into `simulator_libraries/` on first build, and pulls updates on subsequent builds.

## Project layout

- `main.cpp` — game logic and rendering
- `Text.h` — text rendering helpers
- `assets/` — image files (themes, shapes, UI)
- `simulator_libraries/` — OSU Proteus libraries (auto-cloned, not tracked in this repo)
- `Makefile` — top-level build entry point
