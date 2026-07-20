# 🎮 Tic-Tac-Toe in C++ with SFML 3
### An Object-Oriented Graphical Game — COP 3003 Final Project

---

## 📖 Project Overview

This project is a graphical **Tic-Tac-Toe game** built in **C++** using **SFML 3**, developed as the final project for **COP 3003 – Object-Oriented Programming**.

The purpose of this project is to take the object-oriented concepts covered throughout the semester — classes, encapsulation, constructors, composition, and program organization — and apply them to a complete, interactive application. 

**The problem this project solves:** build a working two-player Tic-Tac-Toe game with a graphical interface, but do it in a way that reflects good object-oriented design rather than one giant `main()` function. Instead of tracking the board as a pile of loose variables, the program models the board and its squares as objects with their own data and behavior.

**How it demonstrates OOP:** the project is split into three cooperating classes — `Game`, `Board`, and `Cell` — each with a single, clear responsibility. 
`Game` owns the window and the loop, `Board` owns the grid and the rules, and `Cell` owns a single square. 
Together they demonstrate composition, encapsulation, and the general principle that a well-designed program is a collection of objects talking to each other, not a script with a lot of global state.

---

## 🎯 Learning Objectives

The table below maps rubric-relevant COP 3003 topics to what is actually implemented in this project.

### ✅ Implemented Concepts

| Concept | How It Appears in This Project |
|---|---|
| Classes & Objects | `Game`, `Board`, and `Cell` classes; each is instantiated as an object |
| Constructors | Each class initializes its own state (window, grid, cell value) when constructed |
| Member Functions | `run()`, `processEvents()`, `update()`, `draw()`, `checkWinner()`, `checkDraw()`, `reset()`, and similar functions |
| Encapsulation | Each class keeps its data members private and exposes only the functions other classes need |
| Arrays | `Board` stores its nine `Cell` objects in a fixed-size array |
| Composition | `Game` *has-a* `Board`, and `Board` *has-a* collection of `Cell` objects |
| Header/Source Separation | Every class has a matching `.h` declaration and `.cpp` implementation |
| Game Loop | A loop inside `Game` repeatedly processes events, updates state, and renders |
| Event Handling | Mouse clicks place marks; the **R** key restarts the game |
| Control Structures (Conditionals) | Turn switching, occupied-square checks, win/draw detection, and restart logic |
| Loops | The main loop, board rendering, and win-condition checks |
| GUI Programming (SFML) | Window creation, shape/text rendering, and the render loop all use SFML 3 |

### 🔭 Future OOP Enhancements

The following topics are part of COP 3003 but are **not currently implemented** in this project. 
Each one is revisited in the [Potential Future Implementation](#-potential-future-implementation) section below, with an honest explanation of how it *could* be added rather than a claim that it already exists.

| Concept | Status |
|---|---|
| Inheritance | Not implemented |
| Polymorphism / Virtual Functions | Not implemented |
| Abstract Classes / Interfaces | Not implemented |
| Templates / Generic Programming | Not implemented |
| Exception Handling (`try`/`catch`) | Not implemented |
| Dynamic Memory (`new`/`delete`, smart pointers) | Not implemented — the project currently uses fixed-size, stack-allocated arrays |
| Operator Overloading | Not implemented |

---

## 🔭 Potential Future Implementation

This project satisfies the core OOP topics of the course (classes, objects, encapsulation, constructors, composition, arrays), but it does not currently use several of the more advanced concepts sometimes covered later in the semester. Rather than claim these exist, this section explains **how they could realistically be added** in a future version.

- **Inheritance / Polymorphism:**
  A `Player` base class could be introduced, with `HumanPlayer` and `AIPlayer` as derived classes.
  `Game` would call a virtual `getMove()` function without needing to know which subclass it is talking to.
- **Abstract Classes:**
  The `Player` base class above could be made abstract (a pure virtual `getMove()` function) so that it can never be instantiated directly, forcing every player type to provide its own move logic.
- **Templates:**
  A generic `Grid<T, Rows, Cols>` template class could replace the hardcoded 3×3 `Board`, allowing the same code to support different board sizes.
- **Exception Handling:**
  `try`/`catch` blocks could be added around asset loading (for example, the font file) so the program can display a friendly error message instead of crashing if `Assets/Roboto-Regular.ttf` is missing.
- **Dynamic Memory:**
  If the board size became configurable, the `Cell` array would need to move from a fixed-size stack array to a dynamically sized structure, most likely a `std::vector<Cell>` or smart pointers rather than raw `new`/`delete`.
- **Operator Overloading:**
  `Cell` could overload `==` to simplify comparisons when checking for winning combinations.

---

## 🖥️ Software Requirements

- **Visual Studio 2022** (Desktop development with C++ workload)
- **C++** (C++17 or later)
- **SFML 3**
- **Git**
- **vcpkg** (recommended for installing/managing SFML)
- **Windows** (the build/run instructions below are Windows-oriented)

---

## ⚙️ Installation Instructions

### Step 1 – Clone the Repository
```bash
git clone https://github.com/YOUR_USERNAME/TicTacToe-SFML.git
```
Replace `YOUR_USERNAME` with the GitHub username or organization that owns the repository.

### Step 2 – Open the Project
```bash
cd TicTacToe-SFML
```
Open the Visual Studio solution (`.sln`) file from this folder.

### Step 3 – Install SFML (if needed)
If you're using vcpkg:
```powershell
vcpkg install sfml
```
If Visual Studio is already integrated with vcpkg, the project should automatically locate the SFML libraries.

### Step 4 – Verify the Assets Folder
Confirm the font file used to render X/O and UI text is present:
```text
Assets/
└── Roboto-Regular.ttf
```
If it's missing, copy it in from the repository or download it separately.

### Step 5 – Build and Run
In Visual Studio:
1. Select **Debug** or **Release**.
2. Press **Ctrl + Shift + B** to build.
3. Press **Ctrl + F5** (or **F5**) to run.

If everything is configured correctly, the Tic-Tac-Toe window will open.

---

## 🏗️ Project Structure

### Object Hierarchy
```text
Game
└── Board
    └── Cell (x9)
```
This is a **composition** relationship: `Game` is built out of a `Board`, and a `Board` is built out of nine `Cell` objects. 
None of these classes inherit from one another — the relationship is "has-a," not "is-a."

### File Structure
```text
src/
│
├── main.cpp        # Entry point — creates and starts the Game object
├── Game.h          # Game class declaration
├── Game.cpp        # Game class implementation
├── Board.h         # Board class declaration
├── Board.cpp       # Board class implementation
├── Cell.h          # Cell class declaration
└── Cell.cpp        # Cell class implementation

Assets/
└── Roboto-Regular.ttf   # Font used for rendering X, O, and UI text
```

---

## ▶️ Program Flow

1. Execution begins in `main.cpp`.
2. A `Game` object is created.
3. The `Game` constructor opens the SFML window; the `Board` constructor initializes the grid; each `Cell` constructor sets its value to empty.
4. The SFML window appears on screen.
5. The main game loop in `Game::run()` begins.
6. Each iteration of the loop calls `processEvents()` to handle mouse clicks and key presses.
7. Clicking an empty square updates the corresponding `Cell`'s value to the current player's mark.
8. `Board` checks for a winning combination.
9. If there is no winner, `Board` checks whether the grid is full (a draw).
10. If the game is not over, the current player switches (X ↔ O).
11. `Game::draw()` redraws the window with the updated board state.
12. Pressing **R** calls `reset()`, clearing every `Cell` back to empty and restarting the match.

---

## 🔍 Detailed Explanation of Each Class

### 🎮 `Game`
- **Responsibilities:** Creates and owns the SFML window; runs the main loop; processes keyboard/mouse events; tracks whose turn it is; triggers win/draw checks; handles restart.
- **Attributes (conceptual):** an SFML `RenderWindow`, a `Board` object, and a variable tracking the current player.
- **Methods:** `run()`, `processEvents()`, `update()`, `draw()`.
- **Constructor:** Initializes the window and creates the `Board` object it owns.
- **Relationship to other classes:** `Game` *has-a* `Board` (composition). `Game` is the only class that talks directly to SFML's window/event system.
- **Encapsulation:** The window and player-turn state are private; other code interacts with `Game` only through `run()`.

### 🟦 `Board`
- **Responsibilities:** Stores the nine cells; draws the grid; places marks; checks for a winner; checks for a draw; resets itself.
- **Attributes (conceptual):** a fixed-size array of nine `Cell` objects.
- **Methods:** `checkWinner()`, `checkDraw()`, `reset()`, plus functions to draw the grid and update a specific cell.
- **Constructor:** Initializes all nine cells to empty.
- **Relationship to other classes:** `Board` *has-a* collection of `Cell` objects (composition); `Board` is owned by `Game`.
- **Encapsulation:** The cell array is private; `Game` interacts with the board only through its public functions rather than reaching into individual cells directly.

### ⬜ `Cell`
- **Responsibilities:** Represents one square; stores whether it holds X, O, or is empty; reports whether it's occupied; draws its own value.
- **Attributes (conceptual):** a value representing X / O / Empty.
- **Methods:** functions to get/set its value, check occupancy, and draw itself.
- **Constructor:** Initializes the cell's value to empty.
- **Relationship to other classes:** `Cell` is owned by `Board` (composition); it has no knowledge of `Game` or the rest of the board.
- **Encapsulation:** A `Cell`'s value is private data, only reachable through its own member functions — this keeps the rules for "what counts as a valid mark" inside the class that owns the data.

---

## 💻 Key C++ Concepts

**Classes** organize the program into `Game`, `Board`, and `Cell`, each a blueprint for objects with a specific job.

**Objects** are the actual instances created at runtime — one `Game`, one `Board`, and nine `Cell`s.

**Functions** break behavior into small, testable pieces such as `checkWinner()` and `processEvents()`.

**Arrays** hold the nine `Cell` objects that make up the board in a single fixed-size structure.

**Composition** is how the three classes relate: `Game` contains a `Board`, and `Board` contains `Cell`s, rather than any class inheriting from another.

**Encapsulation** keeps each class's internal data private, exposing only the functions other classes need to call.

**Constructors** guarantee every object starts in a valid state — an empty board, empty cells, and an open window — before gameplay begins.

**Header Files** (`.h`) declare each class's interface — what it can do — without showing how.

**Source Files** (`.cpp`) implement the logic declared in the matching header, keeping declarations and implementation cleanly separated.

**Game Loop** inside `Game` repeatedly processes events, updates state, and redraws the window while it stays open.

**Event Handling** lets SFML report mouse clicks and key presses back to the program so it can react to them.

**Loops** drive the main game loop and repeated checks like scanning the board for a winner.

**Conditionals** decide whether a click is valid, whether a winner exists, whether the board is full, and whether to restart.

**GUI (SFML)** provides the window, shape drawing, and text rendering used to display the board and marks.

---

## 🧠 Algorithms

- **Turn Switching:** After a valid move, the current player flips from X to O (or O to X) using a simple conditional/toggle.
- **Winner Detection:** After each move, the board checks all eight winning lines (three rows, three columns, two diagonals) to see if one player occupies all three cells in any line.
- **Draw Detection:** If no winner is found and every cell is occupied, the game is declared a draw.
- **Restart Logic:** Pressing **R** resets every `Cell` to empty, clears the board's win/draw state, and resets the current player back to X.

---

## 🖼️ Screenshots

> Screenshots to be added before final submission.

| Screen | Image |
|---|---|
| Main Window | `[Insert screenshot here]` |
| Player X Win | `[Insert screenshot here]` |
| Player O Win | `[Insert screenshot here]` |
| Draw | `[Insert screenshot here]` |
| Restart | `[Insert screenshot here]` |

---

## ✅ Demonstration Checklist

- [ ] Launch the application
- [ ] Walk through `main.cpp`
- [ ] Explain the `Game` class
- [ ] Explain the `Board` class
- [ ] Explain the `Cell` class
- [ ] Show the game window
- [ ] Demonstrate mouse input placing marks
- [ ] Demonstrate turn switching
- [ ] Explain the game loop
- [ ] Explain event handling
- [ ] Demonstrate winner detection
- [ ] Demonstrate draw detection
- [ ] Restart the game with **R**
- [ ] Explain composition (`Game` → `Board` → `Cell`)
- [ ] Explain encapsulation in each class
- [ ] Summarize how OOP improved the project's organization

---

## 🚀 Future Improvements

- AI opponent (e.g., minimax algorithm)
- On-screen scoreboard across multiple rounds
- Selectable difficulty levels
- Win/draw animations
- Sound effects
- Networked two-player mode
- Main menu / settings screen
- Undo move
- Save / load game state
- Inheritance & polymorphism (e.g., a `Player` base class)
- Templates (e.g., a generic `Grid<T>` class)
- Exception handling around asset loading
- Dynamic memory (`std::vector`, smart pointers) if the board size becomes configurable

---

## 📚 References

Cppreference. (n.d.). *C++ language reference*. Retrieved from https://en.cppreference.com/

SFML Team. (n.d.). *SFML 3 documentation*. Retrieved from https://www.sfml-dev.org/documentation/3.0.0/

Microsoft. (n.d.). *Visual Studio documentation*. Retrieved from https://learn.microsoft.com/en-us/visualstudio/

GitHub, Inc. (n.d.). *GitHub documentation*. Retrieved from https://docs.github.com/

---

## 🎓 Closing Summary

This Tic-Tac-Toe project demonstrates many of the core concepts taught in COP 3003, including classes, objects, encapsulation, constructors, functions, arrays, composition, event handling, loops, and conditional statements. By dividing the application into the `Game`, `Board`, and `Cell` classes, the project follows object-oriented design principles that keep the code modular, readable, and easier to maintain — while remaining honest about which more advanced OOP topics (inheritance, polymorphism, templates, exceptions, dynamic memory) are left for future versions rather than claimed as already implemented.
