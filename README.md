# 🎮 Build Tic-Tac-Toe in C++ with SFML 3

![C++](https://img.shields.io/badge/C++-Programming-blue)
![SFML](https://img.shields.io/badge/SFML-3.0-green)
![OOP](https://img.shields.io/badge/Object--Oriented%20Programming-orange)
![GitHub Pages](https://img.shields.io/badge/GitHub%20Pages-Documentation-purple)

A beginner-friendly, step-by-step tutorial that teaches students how to build a complete **Tic-Tac-Toe game in C++ using SFML 3**.

This project was created as an educational resource for students learning:

* C++
* Object-Oriented Programming (OOP)
* Game development concepts
* Event-driven programming
* Graphics programming
* Software design principles

The goal of this project is not just to create a working game, but to understand **why the code is structured the way it is**.

---

# 📚 Project Overview

Many beginner programmers learn individual C++ concepts but struggle to understand how those concepts work together in a complete application.

This project bridges that gap by building a real game from the ground up.

Students will learn how to create:

* A graphical window
* A game loop
* A board system
* Interactive cells
* Mouse input
* Keyboard input
* Turn management
* Game states
* Winner detection
* Restart functionality

By the end, students will have created a complete playable Tic-Tac-Toe game.

---

# 🎯 Learning Objectives

After completing this project, students should understand:

## C++ Concepts

* Classes and objects
* Constructors and destructors
* Encapsulation
* Composition
* Header/source file organization
* Functions and parameters
* Arrays
* Conditional logic
* Loops

---

## Object-Oriented Programming Concepts

The project follows a simple OOP structure:

```
Game
 |
 |-- Board
       |
       |-- Cell
```

### Game Class

Responsible for:

* Window management
* Game loop
* User input
* Game state

---

### Board Class

Responsible for:

* Managing the 3x3 grid
* Placing marks
* Checking winners
* Detecting draws

---

### Cell Class

Responsible for:

* Storing one board position
* Tracking X, O, or empty state

---

# 🎮 Game Features

Current features include:

✅ SFML 3 graphics window
✅ Tic-Tac-Toe grid
✅ Mouse-controlled gameplay
✅ X and O turns
✅ Prevent illegal moves
✅ Winner detection
✅ Draw detection
✅ Restart game using keyboard input
✅ Object-oriented design

---

# 🖼️ Screenshots

(Add screenshots here)

Example:

```
images/
|
├── gameplay.png
├── winner.png
└── restart.png
```

---

# 🛠️ Technologies Used

## Programming Language

* C++

## Graphics Library

* SFML 3

## Development Environment

* Visual Studio

## Documentation

* GitHub Pages
* Markdown

---

# 📂 Project Structure

```
TicTacToe-SFML/

│
├── src/
│   |
│   ├── main.cpp
│   ├── Game.cpp
│   ├── Game.h
│   ├── Board.cpp
│   ├── Board.h
│   ├── Cell.cpp
│   └── Cell.h
│
├── Assets/
│   |
│   └── Roboto-Regular.ttf
│
├── README.md
│
└── Documentation/
```

---

# ⚙️ Requirements

Before running this project, install:

## Required Software

* Visual Studio 2022
* C++ Desktop Development workload
* SFML 3

---

# 🚀 Installation

## Step 1: Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/TicTacToe-SFML.git
```

---

## Step 2: Open Project

Open the Visual Studio project.

---

## Step 3: Configure SFML

Make sure SFML libraries are correctly linked.

Required folders:

```
SFML/
 |
 ├── include/
 |
 └── lib/
```

---

## Step 4: Add Assets

Place the font file here:

```
Assets/
 |
 └── Roboto-Regular.ttf
```

---

## Step 5: Build and Run

Compile the project.

Run:

```
Ctrl + F5
```

The game window should appear.

---

# 🎮 How to Play

## Mouse Controls

Click any empty square.

Players alternate:

```
Player X
    ↓
Player O
    ↓
Player X
```

---

## Restart Game

After a game ends:

Press:

```
R
```

to restart.

---

# 🧠 Design Decisions

This project intentionally avoids placing everything inside `main()`.

A beginner approach might look like:

```
main()
 |
 |-- Draw everything
 |-- Handle input
 |-- Check winners
 |-- Reset game
```

However, this quickly becomes difficult to maintain.

Instead, responsibilities are separated:

```
Game
 |
 | controls the application


Board
 |
 | controls the grid


Cell
 |
 | controls one square
```

This follows the software engineering principle:

> Each class should have one clear responsibility.

---

# 📖 Tutorial Website

A complete GitHub Pages tutorial will accompany this project.

The tutorial will cover:

## Lesson 1

Project Setup

## Lesson 2

Creating the SFML Window

## Lesson 3

Object-Oriented Design

## Lesson 4

Drawing the Board

## Lesson 5

Mouse Input

## Lesson 6

Adding X and O

## Lesson 7

Drawing Text

## Lesson 8

Winner Detection

## Lesson 9

Draw Detection

## Lesson 10

Restarting the Game

## Lesson 11

Future Improvements

---

# 🔮 Future Improvements

Possible extensions:

## Beginner Improvements

* Better colors
* Improved fonts
* Animations
* Sound effects
* Score counter

---

## Intermediate Improvements

* Start menu
* Difficulty selection
* Player names
* Themes
* Game history

---

## Advanced Improvements

* Computer AI opponent
* Minimax algorithm
* Online multiplayer
* Networking

---

# 🧪 Practice Challenges

After completing the project, try:

### Challenge 1

Change the board size.

Example:

```
4 x 4 Tic-Tac-Toe
```

---

### Challenge 2

Add a scoreboard.

Example:

```
Player X Wins: 5
Player O Wins: 3
Draws: 2
```

---

### Challenge 3

Create an AI opponent.

---

# 🤝 Contributing

Contributions are welcome!

Students are encouraged to:

* Improve documentation
* Add examples
* Fix bugs
* Suggest improvements

Steps:

1. Fork the repository
2. Create a new branch
3. Make changes
4. Submit a pull request

---

# 📜 License

This project is licensed under the MIT License.

You are free to:

* Use it
* Modify it
* Share it
* Learn from it

---

# 👩‍💻 Author

Created as a learning project to demonstrate:

* C++ programming
* SFML development
* Object-oriented design
* Game development fundamentals

---

# ⭐ Acknowledgements

Special thanks to:

* SFML community
* C++ developer community
* Computer Science educators
* Students learning programming

---

# 🎯 Final Goal

The purpose of this project is simple:

> Learn by building.

Programming becomes easier when concepts are connected to real projects.

This tutorial transforms individual C++ concepts into a complete working application.

Happy coding! 🎮
