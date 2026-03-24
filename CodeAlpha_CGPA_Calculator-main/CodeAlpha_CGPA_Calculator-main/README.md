# CGPA Calculator (C++)

This project is a console based CGPA Calculator written in C++. It is designed to compute semester GPA and overall CGPA by taking structured academic input from the user and processing it using clear, modular logic.

---

## Overview

The program is built around two custom data structures. The Course structure stores individual course information including course name, grade, grade point value, and credit hours. The Semester structure groups multiple courses together and keeps track of total credits, total grade points, and the calculated GPA for that semester. This separation makes the code organized, readable, and easy to maintain.

---

## Grade Processing and Validation

Grade handling is managed through a dedicated function that converts letter grades into numeric grade points using a standard grading scale. User input for grades is validated, and invalid entries are rejected until a correct grade is provided. Credit hours are also validated to ensure only positive values are accepted, preventing incorrect calculations.

---

## GPA and CGPA Calculation Logic

The program processes data semester by semester. For each semester, it dynamically stores course data using vectors, which allows flexibility in handling any number of courses. Once all course data for a semester is entered, total credits and total grade points are calculated, and the semester GPA is derived using these values.

---

## Output Formatting

Results are displayed in a well formatted table showing course names, grades, credit hours, and calculated grade points. Output formatting is handled using stream manipulators to ensure proper alignment and consistent precision. After all semesters are processed, the program computes the final CGPA by combining grade points and credits from every semester.

---

## Code Design

The code follows a modular design, with separate functions responsible for input handling, calculations, grade conversion, and output display. This approach improves readability, simplifies debugging, and makes the program easier to extend in the future, such as adding file handling or support for different grading systems.

---

## Key Technical Highlights

- Uses structures to model real academic entities  
- Applies vectors for dynamic storage of course data  
- Implements input validation for grades and credit hours  
- Separates logic into reusable functions  
- Produces clean and readable formatted output  

---

## Technologies Used

- C++  
- Standard Template Library STL  
- Console input and output  

---

## How to Run

1. Compile the source file using a C++ compiler such as g++  
2. Execute the compiled program  
3. Enter semester and course details as prompted  

---

This project demonstrates practical use of C++ fundamentals including structured programming, data abstraction, input validation, and formatted output, making it a solid example of clean and maintainable academic calculation software.
