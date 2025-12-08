SPEAKEASYOS — OS Simulator
---
Overview
---

SPEAKEASYOS is an educational Operating System simulator designed to demonstrate core OS concepts including:

User authentication

Process creation

CPU scheduling

Virtual memory simulation

Each module is independent, allowing users to explore authentication, process management, scheduling, and memory management separately.

Download
---

Clone the repository using Git:
```
git clone https://github.com/jonathanholguin/SPEAKEASYOS.git
cd SPEAKEASYOS
```
Installation & Usage
---
Authentication Module (Operating System)
```
cd SPEAKEASYOS/Operating System
g++ main.cpp auth.cpp -o auth_sim
auth_sim.exe
```

Process Creation Module (processes)
```
cd SPEAKEASYOS/processes
g++ main.cpp process.cpp -o process_sim
process_sim.exe
```

CPU Scheduling Module (scheduling OS)
```
cd SPEAKEASYOS/schedulingOS
g++ main.cpp scheduler.cpp process.cpp -o scheduling_sim
scheduling_sim.exe
```

Virtual Memory Module (Virtual Memory)
```
cd SPEAKEASYOS/Virtual Memory/Virtual Memory
g++ main.cpp MemoryManager.cpp PageTableEntry.cpp -o vm_sim
vm_sim.exe
```

Note: Each module is independent. Compile and run the main file along with its module-specific .cpp files.

Note
---
This project is for learning and demo purposes only.

Contributors
---

Jonathan Holguin

Arturo Galvez

Alan Verdugo
