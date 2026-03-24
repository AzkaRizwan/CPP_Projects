# Sudoku Solver (C++)

This is a **professional-level Sudoku Solver in C++** designed to solve any valid 9×9 Sudoku puzzle using **recursion and backtracking**. The program is structured for clarity, maintainability, and efficient problem solving.

It uses a 9×9 2D array to represent the grid and applies systematic **constraint checking** to ensure that every number placed is valid according to Sudoku rules. The project demonstrates key programming concepts including recursion, reference parameters, modular design, and input validation.

---

## Overview

The Sudoku Solver allows the user to input a partially filled 9×9 grid, with 0 representing empty cells. It then solves the puzzle automatically using a backtracking algorithm. The solver:

- Finds empty cells
- Tries numbers 1 through 9
- Checks each number against row, column, and 3×3 subgrid constraints
- Places a valid number and recursively continues
- Backtracks if no valid number is possible in a cell
- Continues until the puzzle is completely solved

The program outputs the solved grid in a structured and readable format.

---

## Code Structure

The program follows a **modular design**:

1. **Input Handling**  
   Accepts a 9×9 Sudoku grid from the user, with validation to ensure only numbers 0–9 are entered.

2. **Grid Printing**  
   Displays the Sudoku grid in a clear, formatted manner, separating 3×3 subgrids for readability.

3. **Empty Cell Detection**  
   Locates the next empty cell in the grid to attempt a number placement.

4. **Constraint Checking**  
   Verifies whether a number can be placed in a specific row, column, and 3×3 subgrid without violating Sudoku rules.

5. **Backtracking Solver**  
   Implements the recursive algorithm to try valid numbers, backtrack when necessary, and ultimately solve the puzzle.

6. **Main Control Flow**  
   Orchestrates input, solving, and output.

---

## Key Features

- Fully solves any valid 9×9 Sudoku puzzle  
- Uses recursion and backtracking efficiently  
- Modular function design for clarity and maintainability  
- Proper input validation for grid entries  
- Clean, readable output with clear 3×3 subgrid separation  
- No unnecessary global variables, only a constant for grid size  

---

## Technologies Used

- C++  
- Standard Input/Output  
- 2D Arrays and reference parameters  
- Recursion and backtracking algorithm  

---

## How It Works (High-Level Flow)

1. User enters the Sudoku grid (0 for empty cells)  
2. Solver searches for the first empty cell  
3. Tries numbers 1–9 in that cell  
4. Checks each number against row, column, and subgrid constraints  
5. Places a valid number and recursively solves the next empty cell  
6. If no valid number can be placed, backtracks to previous cell  
7. Repeats until the grid is completely filled or determined unsolvable  
8. Prints the solved Sudoku grid  

---

## Concepts Tested

- Passing 2D arrays to functions  
- Reference parameters to track row and column positions  
- Recursive problem solving  
- Constraint satisfaction logic  
- Backtracking mechanism  

---

## Example Input Format
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

---

Use 0 to represent empty cells.

---

## Why This Implementation Is Professional

- Clear modular functions with single responsibilities  
- Minimal global usage  
- Constants and clean variable naming  
- Fully tested backtracking algorithm  
- Validates inputs to prevent invalid data  
- Cleanly formatted output for readability  

---

This project demonstrates a solid understanding of **recursion, backtracking, and 2D array manipulation in C++**, and is suitable as a professional level algorithmic project.
