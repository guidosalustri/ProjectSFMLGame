# Ribosome — C++ / SFML

A small arcade game about protein synthesis, written in C++ without a game engine.

You play a ribosome moving through the cell, collecting amino acids to build a peptide.
Each amino acid has a colour. Collect one matching your current colour and you score a
point, change colour, and speed up. Collect a mismatched one and you still pick it up,
but score nothing and slow down. The run lasts five spawn waves, after which you enter
your name and your score is written to a persistent leaderboard.

This was my first attempt at building a game.

## No engine

There's no Unity, Unreal or Godot here. **SFML is a media library, not an engine** — it
provides a window, a render target, an input event queue and a clock, and nothing else.
There is no scene tree, no entity system, no physics, no collision detection, no game
loop.

All of that is written from scratch in this repository, which was the point of the
exercise: to build the parts an engine would normally hide.

## Architecture

**`RibosomeGame/`** — the game

| | |
|---|---|
| `Game` | Owns the main loop: poll input, update at delta time, render, present |
| `Entity` | Abstract base deriving from `sf::Sprite`, with pure virtual `Update` and `ResolveCollision` |
| `Ribosome` | The player entity — movement, colour state, speed modifiers |
| `Enemy` | The collectible amino acids — spawning, timing, colour assignment |
| `EntityManager` | Entity registration and lifetime |
| `CollisionManager` | Singleton holding the entity list, detecting overlaps and dispatching resolution |

**`HighScoreManager/`** — a separate project handling score persistence

| | |
|---|---|
| `Score` | A name and value, with equality comparison |
| `leaderBoard` | An ordered score collection with top-N insertion |
| | Read and write to `Scores.dat` between sessions |

Updates are delta-time based, so movement speed is independent of frame rate.

## Building

Visual Studio solution: `ProjectSFMLGame/ProjectSFMLGame.sln`.

SFML 2.x is vendored under `libs/SFML/`, so the solution should build without installing
anything. Windows only — the project files are MSVC-specific.

## Known issues

Documented from testing rather than discovered by someone else:

- The `Game` destructor isn't invoked on exit
- If an amino acid spawns directly on top of the ribosome, the follow behaviour breaks
- The ribosome's background colour makes some collectible colours hard to read,
  magenta especially
- Name entry reads into a fixed-width buffer without bounds checking
- `Source.cpp` includes a `.cpp` file directly rather than its header

## Notes

Scope was cut down substantially from the original design. Source comments are in
Spanish. Textures and font are from open asset packs.

