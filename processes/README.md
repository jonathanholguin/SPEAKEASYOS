==========================================
Operating System Project - Process Simulation
==========================================

Author: Arturo Gálvez, Jonathan Holguin, Alan Verdugo
Language: C++
IDE: Visual Studio Code
Compiler: g++ (MSYS2 UCRT64)
C++ Standard: C++17

------------------------------------------
1️⃣  PROJECT DESCRIPTION
------------------------------------------
This project simulates how an operating system handles processes 
through different states (NEW, READY, RUNNING, TERMINATED).

Each process is represented by a class with attributes such as:
pid (process ID)
arrival time
burst time
priority
state
remaining time
waiting time
turnaround time

The simulation manually progresses through time steps to show 
how processes move between states.

------------------------------------------
2️⃣  HOW TO CLONE THE REPOSITORY
------------------------------------------
If you want to run or modify this project, clone it using Git.

Open a terminal and navigate to where you want to save the project.
Run the following command:

   git clone https://github.com/<your-username>/<your-repository-name>.git

Open the cloned folder in Visual Studio Code:
From VS Code: File → Open Folder → select the cloned folder.

You should see files like:
main2.cpp
process.cpp
process.hpp
authentication.cpp (if included)

------------------------------------------
3️⃣  FILE STRUCTURE
------------------------------------------
main2.cpp        → Contains the simulation (main function)
process.cpp      → Implementation of the Process class
process.hpp      → Header file for the Process class
authentication.cpp / .hpp  (optional) → Handles user login system
README.txt       → Instructions on how to run the project

------------------------------------------
4️⃣  HOW TO SET UP MSYS2 (if not already installed)
------------------------------------------
Download MSYS2 from: https://www.msys2.org/
Open the “MSYS2 UCRT64” terminal.
Run:
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc
Verify g++ installation:
g++ --version

------------------------------------------
5️⃣  HOW TO RUN THE PROJECT IN VISUAL STUDIO CODE
------------------------------------------
Open the project folder in VS Code.
Open a terminal (Ctrl + `).
Compile the project:
g++ -std=c++17 main2.cpp process.cpp -o main2.exe
Run the executable:
main2.exe

------------------------------------------
6️⃣  OPTIONAL: CREATE A BUILD TASK (one-key build)
------------------------------------------
You can automate building inside VS Code:

Press Ctrl + Shift + B
Choose “C/C++: g++.exe build active file”
Or create a .vscode/tasks.json file:

{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build OS Simulation",
      "type": "shell",
      "command": "C:\msys64\ucrt64\bin\g++.exe",
      "args": ["-std=c++17", "main2.cpp", "process.cpp", "-o", "main2.exe"],
      "group": "build",
      "problemMatcher": []
    }
  ]
}

Now you can press Ctrl + Shift + B to compile automatically.

------------------------------------------
7️⃣  SAMPLE OUTPUT
------------------------------------------
Time = 0
Process 1 is now READY.
Process 1 is now RUNNING.
Process 1 has TERMINATED.
CPU is idle.
