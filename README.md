# Indie Studio

![](bomberman.png)

> binary name: `bomberman` <br>
> language: `c` <br>
> compilation: `cmake 3.17`

The aim of the **Indie Studio** is to implement a **cross-platform** 3D video game with **real-world** tools.

Making an enjoyable game is just as important as writing clean code.<br>
A working game which is no fun to play is pointless!

> Let’s be honest. Implementing a video game is generally not fun (at least not all the time).
> But it can be, and having someone else enjoy a game you made is an amazing feeling.
> The result will be worth the effort, so do your best! And most importantly, **have fun**
 
## Compilation

You **MUST** use **CMake** as a cross-platform build system:

- **Linux**: it must generate a `Makefile` to be able to build the project
- **Windows**: it must generate a Visual Studio solution `.sln` (will be tested with Visual Studio 2022)

> We will provide a `CMAKE_MODULE_PATH` cmake variable when building the project.

## Library

You must use `raylib`, a very simple C library for 2D/3D graphics. As of today, 3D animation for `.gltf` models
files is badly handled. We advised you to use multiple `.obj` files to animate your assets.

> `raylib` is a C library, ever heard of encapsulation ?

A CMakes module is provided for `raylib`, you must use it to generate your project. You mays use `Boost` to help you with some aspects of the project (or for bonuses).

> There are plenty of free assets on the Internet. Creating your own should be far from being a priority. . . Do not waste time.
 
## The game

The game you must implement is a Bomberman-like game.<br>
**Bomberman** is one of the most famous video games of all time.<br>
With over 70 franchises, ranging from the first version on MSX, ZX Spectrum and Sharp MZ-700 in 1983 to the latest versions on modern consoles, over 10 million units have been sold.

Our gameplay reference is **Neo Bomberman**, released on the Neo Geo and MVS systems in 1997.

Here’s the required features:

- Local multiplayer with the possibility to play with a friend + AI’s controlled bots.
- A main game menu (to start a new game or load an existing one).
- Your game must feature 3D graphics but a 2D gameplay.
- Your game must feature **procedurally generated maps** (random obstacles, random bonus. . . ).
- Save/Load a game
- Animation and sounds to give life to the game (especially during various interactions)
  - Think about bomb explosion, player walking, background music, ...
- Some Power-ups
  - Bomb Up
  - Speed Up
  - Fire Up
  - Wall Pass

The goal of this project is not only to code a video game, but it’s to code a fully finished video game. 

This means that the efforts you make to polish your game will count as much as the technical aspect.

Do your best to avoid clunky animations or graphical glitches, manage your camera in a way that the “out-side” of the game is never visible, pay attention to game design, level design and sound design, add variations in enemies and environments, etc.