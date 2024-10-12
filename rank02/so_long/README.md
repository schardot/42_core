# so_long 🏞️🚶‍♂️

![Demo GIF](https://github.com/schardot/42_core/blob/main/rank02/so_long/schardot_so_long.gif)

The **so_long** project is a 2D game developed as part of the 42 curriculum, focusing on navigating through a maze, collecting items, and finding the exit. The challenge lies in creating an engaging gameplay experience while managing player movement and map interactions.

## Project Overview

In **so_long**, you control a player character who must navigate a grid-based map filled with walls, collectibles, and an exit point. Your objective is to collect all the items on the map and reach the exit, all while avoiding obstacles.

## Features

- **Interactive Gameplay**: Move your character using keyboard controls to navigate through the map.
- **Collectibles**: Gather items scattered throughout the maze to complete the game.
- **Exit Point**: Reach the designated exit after collecting all items to win the game.
- **Simple Graphics**: Built with the MiniLibX graphics library for easy rendering.

## Allowed Operations

The player can perform the following movements:

- **Arrow Keys**: Move the player character in four directions:
  - **Up**: Move the player up the grid.
  - **Down**: Move the player down the grid.
  - **Left**: Move the player left on the grid.
  - **Right**: Move the player right on the grid.

### Game Mechanics

- **Walls**: Represented by the character '1', these are impassable barriers that the player cannot cross.
- **Empty Spaces**: Represented by '0', these are the traversable areas where the player can move.
- **Collectibles**: Represented by 'C', these items must be collected to complete the game.
- **Exit**: Represented by 'E', this is the endpoint that the player must reach after collecting all items.

## Gameplay

The goal is to navigate through the maze, collect all collectibles, and reach the exit. The player can move freely but must avoid walls and obstacles.

### How It Works

When the game starts, the player is placed at the designated starting position on the map. The player can use the arrow keys to move around the grid, collecting items as they go. Upon collecting all items, the player must reach the exit to complete the game.

