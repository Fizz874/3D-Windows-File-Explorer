# 3D-Windows-File-Explorer

A graphical 3D file explorer designed as an attempt to 
reimagine file management from a completely new perspective.

In this program, the seemingly mundane task of finding a file takes 
on a sense of adventure, like navigating a fortress in search of hidden treasures.


## Controls

- **Up Arrow** - Move forward  
- **Down Arrow** - Move backward  
- **Left Arrow** - Rotate left  
- **Right Arrow** - Rotate right  
- **W** - Move camera up  
- **S** - Move camera down  
- **Left Shift** - Sprint  
- **Enter** - Enter folder / Open file  
- **Escape** - Exit application  


## How to Run the Program

1. Clone the repository.
2. Open the solution file of the project (`.sln`) in Visual Studio.
3. In the file `main_file.cpp`, modify the value of the variable `initPath`  
   to match the absolute path of the folder on your computer  
   where you intend to start the search 
(use double backslashes (`\\`) in the path instead of singular ones (`\`)).
4. Press `Ctrl+Shift+B` to build the project.
5. Press `F5` to run the program.

## Technologies

The program was written in C++ using Visual Studio. 
It runs on Windows and uses GLFW and OpenGL for managing windows, handling input, and rendering 3D graphics.

## Authors

- [Filip Baranowski](https://github.com/Fizz874)
- [Wiktor Makowski](https://github.com/veektorf1)
