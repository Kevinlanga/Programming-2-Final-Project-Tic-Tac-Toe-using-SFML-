# 🎮 Tic-Tac-Toe in C++ with SFML 3

## Project Overview

This project is a graphical **Tic-Tac-Toe game** developed in **C++** using **SFML 3** as part of **COP 3003 – Object-Oriented Programming**.

The purpose of this project is to demonstrate how the core concepts learned in class can be applied to build a complete interactive application. Rather than placing all of the code inside `main()`, the program is organized into multiple classes that each have a specific responsibility. This approach makes the program easier to read, maintain, and expand.

---

# 🎯 Learning Objectives

This project demonstrates the following concepts taught in **COP 3003**:

- Classes and Objects
- Encapsulation
- Constructors
- Member Functions
- Arrays
- Object-Oriented Design
- Composition
- Header (`.h`) and Source (`.cpp`) Files
- Program Organization
- Separation of Responsibilities
- Game Loop
- Event Handling
- User Input
- Conditional Statements
- Loops

---

# 🏗️ Object-Oriented Design

The project is organized using three primary classes.

```text
Game
└── Board
    └── Cell
```

This structure demonstrates **composition**, where larger objects are built from smaller objects that each perform a specific task.

## 🎮 Game Class

### Responsibilities

- Creates the game window
- Runs the main game loop
- Processes keyboard and mouse events
- Keeps track of the current player
- Checks for wins and draws
- Restarts the game when **R** is pressed

### Why It Was Used

The `Game` class manages the overall application and coordinates communication between the other classes. Keeping this logic inside one class allows `main.cpp` to remain simple.

---

## 🟦 Board Class

### Responsibilities

- Stores the nine game cells
- Draws the Tic-Tac-Toe board
- Places X and O marks
- Checks for winning combinations
- Detects draw conditions
- Resets the board

### Why It Was Used

The `Board` class separates all game-board logic from the rest of the application, improving readability and maintainability.

---

## ⬜ Cell Class

### Responsibilities

- Represents one square on the board
- Stores X, O, or Empty
- Determines whether the square is occupied
- Draws its current value

### Why It Was Used

Each square is represented as its own object, allowing data and behavior to remain together while demonstrating object-oriented design.

---

# 📂 File Structure

```text
src/
│
├── main.cpp
├── Game.h
├── Game.cpp
├── Board.h
├── Board.cpp
├── Cell.h
└── Cell.cpp
```

## main.cpp

- Entry point of the application
- Creates a `Game` object
- Starts the program

---

## Game.h / Game.cpp

Contains the `Game` class.

Responsibilities include:

- Creating the SFML window
- Running the game loop
- Processing events
- Updating the game state
- Drawing objects
- Restarting the game

---

## Board.h / Board.cpp

Contains the `Board` class.

Responsibilities include:

- Managing the 3×3 grid
- Updating board positions
- Checking for winners
- Checking for draws
- Resetting the game board

---

## Cell.h / Cell.cpp

Contains the `Cell` class.

Responsibilities include:

- Representing one square
- Storing X, O, or Empty
- Determining whether the cell is occupied
- Drawing the cell

---

# 💻 Key C++ Concepts Used

## 📦 Classes and Objects

**What it is**

A class is a blueprint used to create objects.

**Where it appears**

- `Game`
- `Board`
- `Cell`

**Why it was used**

Classes organize the application into logical components with clearly defined responsibilities.

---

## 🔒 Encapsulation

**What it is**

Encapsulation keeps data private and provides public member functions to safely interact with it.

**Where it appears**

Each class stores its own data members and exposes only the functions needed by other classes.

**Why it was used**

Encapsulation protects important data and improves program organization.

---

## 🏗️ Constructors

**What it is**

Constructors initialize objects when they are created.

**Where it appears**

- `Game` constructor initializes the game window.
- `Board` constructor initializes the game board.
- `Cell` constructor initializes each square as empty.

**Why it was used**

Constructors ensure every object starts in a valid state before gameplay begins.

---

## ⚙️ Member Functions

**What it is**

Functions perform specific tasks within a class.

**Where it appears**

Examples include:

- `run()`
- `processEvents()`
- `update()`
- `draw()`
- `checkWinner()`
- `checkDraw()`
- `reset()`

**Why it was used**

Breaking the program into smaller functions improves readability, reuse, and debugging.

---

## 🧮 Arrays

**What it is**

Arrays store multiple values of the same type.

**Where it appears**

The `Board` class stores the nine game cells in a fixed-size array.

**Why it was used**

Arrays efficiently represent the 3×3 Tic-Tac-Toe board.

---

## 🧩 Composition

**What it is**

Composition means one class contains objects of another class.

**Where it appears**

- `Game` contains a `Board`
- `Board` contains multiple `Cell` objects

**Why it was used**

Composition separates responsibilities while allowing the classes to work together as one application.

---

## 📄 Header and Source Files

**What it is**

Header files declare classes and functions, while source files contain their implementations.

**Where it appears**

- `Game.h` / `Game.cpp`
- `Board.h` / `Board.cpp`
- `Cell.h` / `Cell.cpp`

**Why it was used**

Separating declarations from implementations improves organization and follows standard C++ programming practices.

---

## 🔄 Game Loop

**What it is**

The game loop continuously updates the application while the window remains open.

**Where it appears**

Inside the `Game` class.

**Why it was used**

The game loop allows the program to repeatedly process input, update the game, and redraw the window.

---

## 🖱️ Event Handling

**What it is**

Event handling allows the program to respond to user actions.

**Where it appears**

- Mouse clicks place X and O.
- Keyboard input detects when the **R** key is pressed.

**Why it was used**

Event handling makes the application interactive.

---

## ⌨️ User Input

**What it is**

User input allows players to control the application.

**Where it appears**

- Mouse clicks select board positions.
- Keyboard input restarts the game.

**Why it was used**

Without user input, players would not be able to interact with the game.

---

## 🔀 Conditional Statements

**What it is**

Conditional statements allow the program to make decisions.

**Where it appears**

Examples include:

- Checking if a square is empty
- Switching player turns
- Detecting a winner
- Detecting a draw
- Restarting the game

**Why it was used**

Conditionals control the game's logic and enforce the rules.

---

## 🔁 Loops

**What it is**

Loops repeatedly execute code while a condition remains true.

**Where it appears**

- Main game loop
- Drawing the board
- Checking winning combinations

**Why it was used**

Loops efficiently repeat operations throughout the game.

---

# ▶️ How the Program Works

The game follows this sequence:

1. The program begins in `main.cpp`.
2. A `Game` object is created.
3. Constructors initialize the game window and board.
4. The SFML window opens.
5. The main game loop begins.
6. User input is continuously processed.
7. Clicking an empty square updates the corresponding `Cell`.
8. The `Board` checks for a winner.
9. If no winner exists, the program checks for a draw.
10. If the game continues, the current player switches.
11. The updated board is redrawn.
12. Pressing the **R** key resets the board for a new game.

---

# ✅ Demonstration Checklist

During the presentation, demonstrate the following:

- Launch the application
- Explain `main.cpp`
- Explain the `Game` class
- Explain the `Board` class
- Explain the `Cell` class
- Show the game window
- Demonstrate mouse input
- Demonstrate turn switching
- Explain the game loop
- Explain event handling
- Demonstrate winner detection
- Demonstrate draw detection
- Restart the game using the **R** key
- Explain composition
- Explain encapsulation
- Explain how object-oriented programming improved program organization

---

# 🎓 Closing Summary

This Tic-Tac-Toe project demonstrates many of the core concepts taught in **COP 3003**, including classes, objects, encapsulation, constructors, functions, arrays, composition, event handling, loops, and conditional statements.

By separating the application into the **Game**, **Board**, and **Cell** classes, the project follows object-oriented design principles that make the code modular, organized, and easier to maintain.

Overall, the project shows how fundamental C++ concepts work together to create a complete, interactive application while reinforcing the software engineering principles learned throughout the course.
