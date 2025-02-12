## Description

Project aimed at creating a 2D game using the **MLX42** library. A system must be designed in which the player can move through a map, collect objects, and reach the exit under certain conditions.

🇪🇸 [Leer en Español](README_ES.md)

<img alt="krub wannabe icon" src="https://iili.io/2maloV1.png">

## Project Structure

### Makefile

- Rules: `all`, `clean`, `fclean`, `re`.
- Must not relink files under any circumstances.

## Function Files

- `so_long.c`: Main function of the program.
- `level.c`: Map handling and its characteristics.
- `check_level.c`: Level validation ensuring it meets the rules.
- `check_path.c`: Implementation of **Flood Fill** to verify if there is a valid path.
- `game.c`: Game initialization and main loop handling.
- `game_utils.c`: Auxiliary functions related to screen configuration.
- `displayPlayer.c`: Loading and rendering of the player sprite.
- `displayEnv.c`: Rendering of the background and map borders.
- `displayCollectibles.c`: Handling and visualization of collectible objects.
- `displayExit.c`: Handling and visualization of the exit.
- `playerController.c`: Player control, user input detection.
- `interactions.c`: Collision detection and movement validation.
- `error_exit_free.c`: Error handling and memory release.

## Game Rules

- The player must collect all objects (`C`) to be able to exit (`E`).
- Movement using **WASD** or arrow keys.
- Walls (`1`) cannot be traversed.
- The number of movements is displayed in the terminal and on-screen for the bonus.

## Allowed Libraries and Functions

- **Authorized functions**: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`.
- **MiniLibX/MLX42**: Mandatory use for graphics and rendering.
- **Libft**: Allowed for auxiliary functions.
- **Math Library (-lm)**: Allowed.

## Map Validation Algorithm

The **Flood Fill/DFS** algorithm is used to verify that the player can reach the exit while collecting all collectibles. It uses recursion. This method ensures that the level is playable before starting the game.

## Bonus

- Implementation of enemies/traps that can make the player lose.
- Sprite animations to enhance the visual experience.
- Displaying the movement counter on-screen instead of the terminal.

<img alt="krub wannabe screenshot game" src="https://iili.io/2maY6bI.png">

## Final Considerations

This project has been a great introduction to 2D game development. In addition to applying **MLX42**, work has been done on map validation, graphics optimization, and user interaction.

Design was prioritized before implementation, allowing for a more structured and efficient development. I also had to adjust expectations to deadlines. In the future, the project may evolve or be adapted to other game engines such as **Godot** or **Unity**.

