# 🏦 Bank Management System – Extended Version (C++ Console Application)

This project is an **extended console-based Bank Management System** developed in **C++**, building upon my previous experience with structured programming and file handling. It represents a **complete banking simulation** that allows managing client accounts and performing financial transactions with **data persistence**.  

---

## 🎯 Project Objective

The main goals of this project are:

- Enhance the previous bank management system with **transaction management features**  
- Implement **deposit and withdrawal operations**  
- Calculate and display **total balances** for all clients  
- Maintain a **persistent storage system** using files  
- Reinforce structured programming, modular functions, and user interaction  

---

## 🧠 Learning Outcomes

Through this project, I gained practical experience in:

- Writing **organized and maintainable C++ code**  
- Using `struct` and `vector` to manage dynamic client data  
- Implementing **file-based persistent storage**  
- Building **menu-driven console applications**  
- Handling **user input validation and error checking**  
- Applying **CRUD operations** and financial transactions  
- Simulating **real-world banking logic** in a console environment  

---

## ✨ System Features

The system allows the user to:

- 📋 **Display all clients** with detailed information  
- ➕ **Add new clients** with unique account numbers  
- 🔍 **Search for clients** by account number  
- ✏️ **Update client information**  
- 🗑️ **Delete clients** with confirmation  
- 💰 **Deposit and withdraw balances** for clients  
- 📊 **Show total balances** of all clients  
- 💾 **Persist data** to a text file between program runs  
- 🧭 Navigate through a **clear, menu-driven interface**  

---

## 🧱 Data Structure

Each client in the system has the following fields:

- **Account Number**  
- **Pin Code**  
- **Client Name**  
- **Phone Number**  
- **Account Balance**  
- **MarkForDelete** (boolean used internally for soft deletion)

Data is organized using a `struct` and stored dynamically in a `vector` for easy management.

---

## 📂 File Storage

- All client data is stored in a **text file (`ClientsData.txt`)**  
- A **custom separator (`#//#`)** is used to parse and reconstruct records  
- The system updates the file after:  
  - Adding a client  
  - Updating client information  
  - Deleting a client  
  - Performing deposits or withdrawals  
- This ensures **data persistence** across program executions  

---

## 🛠️ Programming Concepts Applied

The project applies the following C++ concepts:

- `struct` for **data organization**  
- `vector` for **dynamic arrays**  
- `fstream` for **file input/output**  
- Functions and **modular programming**  
- Input validation and error handling  
- Menu-driven **program flow**  
- **CRUD operations** (Create, Read, Update, Delete)  
- **Financial transactions logic** (Deposit & Withdraw)  

---

## ▶️ How the Program Works

1. The program starts by displaying the **Main Menu**  
2. Users can navigate through options to:  
   - List clients  
   - Add, update, or delete clients  
   - Search for a client  
   - Perform transactions (Deposit/Withdraw)  
3. Transaction operations include **confirmation prompts**  
4. Data is **read from and written to the file** as needed  
5. Users can return to the main menu or exit the program  

---

## 🚀 Why This Project Matters

This project is a key milestone because it demonstrates:

- Transition from **basic programming tasks** to a **full banking system**  
- Application of **real-world logic** in a console application  
- Integration of **CRUD operations and financial transactions**  
- Understanding of **persistent storage using files**  

It lays a strong foundation for future projects in:

- Object-Oriented Programming (OOP)  
- Advanced C++ applications  
- Real-world system simulations  

---

## 👤 Author

**Ahmed Zakaria**  
Junior Software Developer  
Focused on **C++ programming** and **problem-solving**

---

⭐ This extended bank management system reflects my ability to **build functional and interactive applications**, manage client data, and implement **realistic banking logic** in C++.
