# Vector Lab Branch - Gabi

## Description
This program lets you store vectors and perform operations on them.

## Building the Program
1. Open a terminal in the project folder.
2. Run `make`

Or compile manually with:
`gcc -o main main.c vectorStorage.c vectorMath.c -lm`

## Running the Program
Run the program with `./main`

### Command Line Options
- `-h` - Displays the help menu (`./main -h`).

## Supported Commands

### General
- `help` - Opens a menu that describes the commands.
- `quit` - Exits the minimat program.
- `clear` - Clears all saved vectors from memory.
- `list` - Prints a list of all saved vectors to the console.

### Assigning and Viewing Vectors
- `a = x y z` - Assigns x, y, and z values to a vector `a` (z may be left blank if 0).
  - Overwrites a previous save of the same name.
  - Only saves if space allows.
- `a` - Displays the current values stored in `a`.

### Operations
- `a + b` - Adds vectors `a` and `b` and displays the result (not stored).
- `a * b` - Calculates and reports the dot product of `a` and `b`.
- `a x b` - Calculates and reports the cross product of `a` and `b`.
- `c = a + b` or `c = a - b` - Adds or subtracts `a` and `b`, stores the result in `c`, and displays it.
- `a = b * n` or `a = n * b` - Multiplies vector `b` by number `n` and stores the result in `a`.

## Dynamic Memory Usage
Dynamic memory is used to store the array of vectors for the program.
The array starts with room for 10 vectors and resizes to fit as many vectors as space allows.
The array is static to `vectorStorage.c`, and its memory is freed from that file before the program closes.