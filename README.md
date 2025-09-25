# 📝 C++ To-Do List (OOP Project)

## 📌 Overview
This is a simple **To-Do List application written in C++** using **Object-Oriented Programming (OOP)** concepts.  
It supports:
- Normal tasks
- Deadline tasks
- Priority tasks  

Each task can be marked as **done**, and all tasks are displayed with their details.

---

## ✨ Features
- ➕ Add **normal tasks** (title + category)  
- 📅 Add **deadline tasks** (title + category + deadline)  
- ⚡ Add **priority tasks** (title + category + priority level)  
- 👀 View all tasks with status (`[X]` for pending, `[./]` for done)  
- ✅ Mark a task as done  
- 🗑️ Automatically frees memory when program exits  

---

## 🛠️ Tech Used
- Language: **C++**  
- Concepts: Classes, Inheritance, Polymorphism, Dynamic Memory  

---

## ▶️ How to Compile & Run
### Using g++:
```bash
g++ todo.cpp -o todo
./todo
```

### Menu Options:
```
1. Add Normal Task
2. Add Task with Deadline
3. Add Task with Priority
4. Show all Tasks
5. Mark a Task Done
6. EXIT
```

---

## 📂 Project Structure
```
cpp-todo-list/
│── todo.cpp       # Main source code
│── README.md      # Project documentation
│── .gitignore     # Ignore build files
│── LICENSE        # MIT License
```

---

## 📸 Example Run
```
TODO LIST MENU
1.Add Normal Task
2.Add Task with Deadline
3.Add Task with Priority
4.Show all Tasks
5.Mark a Task Done
6.EXIT
ENTER CHOICE: 1
Enter task title: Homework
Enter task category: School

TODO LIST MENU
1.Add Normal Task
...
ENTER CHOICE: 4

TODOLIST
1. [X] Title: Homework - Category: School
```

---

## 📜 License
This project is licensed under the **MIT License** – you are free to use, modify, and distribute it.  

👤 Author
Mahnoor Sohail
GitHub:mahnooroshail418-collab
📧 Email::mahnoorsohail1418@gmail.com
