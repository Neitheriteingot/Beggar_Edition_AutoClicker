# Simple Auto Clicker For Windows 

## Core Features
An ultra-lightweight auto-clicking tool that enables automatic continuous left-clicking of the mouse, with support for custom delay time.

## Features
- **Fast Response**: Implemented based on Windows API, ensuring efficient execution of click commands without redundant processing and extremely fast startup.
- **Concise Design**: The core code consists of only over 70 lines, with focused functionality and no unnecessary modules.
- **Easy Operation**: All operations can be completed via hotkeys, eliminating the need for complex configurations.

## Operation Instructions
- **F8 Key**: Toggle the auto-clicking state (can be enabled/disabled in any window)
- **F10 Key**: Set the click delay time (must be used when the console window is in focus; minimum 10ms)
- **ESC Key**: Exit the program (must be used when the console window is in focus)

## Working Mechanism
When enabled, the program will automatically perform left-click operations at the current mouse position according to the set delay time (default 500ms), repeating the process in a loop until it is disabled or exited.
