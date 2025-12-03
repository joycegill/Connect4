# Networked Connect 4

This is the final project for CSC 213: Operating Systems and Parallel Algorithms by Joyce Gill and Engtieng Ourn. The project implements a Connect 4 game using the `ncurses` library in C with round-robin thread scheduling and networks.

## Operating Systems Concepts

The following OS concepts are demonstrated in this project:
1. **Scheduling** - Round Robin Fashion
2. **Parallelism with Threads** - Two player threads run concurrently
3. **Thread Synchronization** - Mutexes and condition variables coordinate access
4. **Networks** - TODO!

## Architecture

### Threading Model

The game uses a multi-threaded architecture with round-robin scheduling:
- **Main Thread**: Handles user input (arrow keys, spacebar) and display updates
- **Player 1 Thread**: Processes moves for Player 1
- **Player 2 Thread**: Processes moves for Player 2

Threads use mutexes and condition variables to ensure:
- Only one thread accesses shared state at a time
- Threads wait for their turn (round-robin scheduling)
- Proper synchronization between input and move processing

### Synchronization Primitives

- **`pthread_mutex_t`**: Protects shared game state from race conditions
- **`pthread_cond_t`**: Coordinates turn-taking between player threads
- **Condition Variables**: Threads wait until it's their turn and a move is available

## Game Rules

- Players take turns placing tokens in columns
- Tokens drop to the lowest available row in the selected column
- First player to get 4 tokens in a row (horizontal, vertical, or diagonal) wins
- If the board fills completely with no winner, the game ends in a draw

## Controls

- **Arrow Keys (← →)**: Move cursor to select column
- **Spacebar**: Place token in selected column
- **q**: Quit the game

## How to Build and Run

To compile and run the project, use the provided `Makefile`. 

```bash
make
```

```bash
./connect4
```

## Dependencies

- `ncurses` - Terminal UI library for drawing the game board
- `pthread` - POSIX threads library for threading and synchronization

## Compilation

The Makefile compiles with:
- `-Wall -Wextra`: Enable all warnings
- `-std=c99`: C99 standard
- `-lncurses -pthread`: Link ncurses and pthread libraries

## Project Structure

- `main.c` - Main game implementation with threading and synchronization
- `Makefile` - Build configuration
- `README.md` - This file
