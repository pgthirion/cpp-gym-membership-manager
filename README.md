# Gym Membership Manager 🏋️
### BSc Information Technology (Network and Security Engineering) - Year 1
**Institution:** Eduvos | **Module:** Procedural Programming

## Overview
This is a menu-driven application designed to manage user accounts for a fitness center. It functions as a basic CRUD (Create, Read, Update, Delete) system that creates profiles, manages a digital currency (credits), and books sessions.

## Features
* **Menu Interface:** A persistent loop allowing multiple actions in one session.
* **Account Management:** Create profiles with generated IDs.
* **Credit System:** Add credits and "spend" them to book sessions.
* **Input Validation:** Robust checking ensures users cannot enter negative numbers or invalid characters.

## Concepts Demonstrated
* **Pass-by-Reference:** Modifying variables (credits, names) inside functions to persist changes in `main()`.
* **Input Streams:** Using `cin.fail()` and `cin.ignore()` to handle bad user input gracefully.
* **Switch-Case:** Handling menu navigation logic.
* **Modular Design:** Breaking down complex logic into single-responsibility functions.

## How to Run
This is a standalone C++ file. You can compile it using G++, Clang, or MSVC.

**Using Terminal (G++):**
1.  Compile the code:
    ```bash
    g++ GymMembershipManager.cpp -o gym_manager
    ```
2.  Run the application:
    ```bash
    ./gym_manager
    ```
    *(On Windows, run `gym_manager.exe`)*
