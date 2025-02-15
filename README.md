# Snake Game in C

## Overview
This project is a simple Snake game implemented in C, utilizing ANSI escape codes for terminal graphics. The game allows the player to control a snake that moves around the board, consumes food, and grows in length. The game ends when the snake collides with the walls or itself.

## Features
- Terminal-based snake game
- Adjustable board size
- Food spawns randomly on the board
- Snake grows upon consuming food
- Game-over condition when the snake collides with the walls or itself
- Real-time keyboard input without requiring ENTER key

## Dependencies
This game relies on standard C libraries:
- `stdio.h`
- `stdlib.h`
- `termios.h`
- `time.h`
- `sys/select.h`
- `unistd.h`
- `function.h` (Custom header file for additional functions)

## Compilation
To compile the game, use the following command:
```sh
gcc -o snake_game main.c function.c -Wall
```

## How to Play
1. Run the compiled program:
   ```sh
   ./snake_game
   ```
2. Enter the size of the game board.
3. Use the following keys to control the snake:
   - `W` - Move Up
   - `A` - Move Left
   - `S` - Move Down
   - `D` - Move Right
   - `Q` - Quit the game
4. The goal is to collect food (`*`) to grow the snake (`o`) while avoiding collisions.
5. The game ends when the snake hits the walls or itself.
6. The final score is displayed upon losing.

## Functions Overview
- `kbhit()`: Checks if a key has been pressed.
- `setInputMode()`: Configures terminal input mode to read keys without requiring ENTER.
- `restore_terminal()`: Restores normal terminal settings.
- `death_condition()`: Checks if the snake collides with walls or itself.
- `search()`: Searches if a given position is part of the snake’s body.
- `matrix()`: Draws the game board on the terminal.
- `position()`: Updates the snake's position based on user input.
- `make_random()`: Places food randomly on the board.
- `make_one_random()`: Generates a random position within boundaries.
- `verif_pos()`: Checks if the snake has eaten food and updates its length.

## Game Flow
1. The game initializes the board and places food at random positions.
2. The player uses the keyboard to move the snake.
3. The game checks for collisions and updates the snake’s length upon eating food.
4. If the snake collides with itself or the walls, the game ends and the final score is displayed.

## Notes
- This game uses ANSI escape codes to clear and update the terminal screen efficiently.
- The game speed is controlled using `usleep(300000)`, which can be adjusted for different difficulty levels.
- The `termios` library is used to process keyboard inputs without requiring ENTER.

## License
This project is open-source and free to use for educational and personal projects.

---
Enjoy playing the Snake game in your terminal!

