# Advanced To-Do List Manager

## Description
A robust command-line to-do list manager built in C, designed to organize tasks with advanced features. Users can add tasks with priority levels (High, Medium, Low), mark them as completed, delete them, and view them sorted by priority. Tasks are persistently stored in a binary file, showcasing efficient data management and pointer usage.

## Features
- Add tasks with a description and priority (1=High, 2=Medium, 3=Low).
- Mark tasks as "Completed" by ID.
- Delete tasks by ID.
- Display tasks sorted by priority with status (Pending/Completed).
- Persistent storage in a binary file (`tasks.dat`) for reuse across sessions.

## Technologies Used
- **C**: Structs, pointers, and dynamic memory management.
- **File Handling**: Binary file I/O using `fread` and `fwrite`.
- **Sorting**: Bubble sort algorithm to order tasks by priority.
- **Modularity**: Separate functions for each operation.

## How to Run
1. **Prerequisites**: A C compiler (e.g., gcc, MinGW, or an IDE like Code::Blocks).
2. **Clone the Repository**:
   ```bash
   git clone https://github.com/Gobikrishnanpro/AdvancedToDoList.git
   cd AdvancedToDoList
3. **Compile Code**:
   ```bash
   gcc AdvancedToDoList.c -o todo
4. **Run Code**:
   ```bash
   ./todo
## Sample Usage
Add: Choose 1, enter Finish project, priority 1 → Task added with ID 1.
Display: Choose 2 → Shows tasks sorted (e.g., "1 | Finish project | High | Pending").
Complete: Choose 3, enter 1 → Updates to "Completed".
Delete: Choose 4, enter 1 → Removes task.

## File Structure
AdvancedToDoList.c: Main source code.
tasks.dat: Binary file storing tasks (generated on first run).

## Author
**Gobi Krishnan** - A Java Full-Stack student pushing boundaries with C programming.

## License
This project is open-source under the MIT License.
