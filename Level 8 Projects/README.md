# 💻 Level 8 Projects

This folder contains my Level 8 projects while learning advanced **C++ and Software Engineering concepts**.

---

## 🏦 1. Bank System (Extension 2)

### 📌 Overview

A full-featured **Bank Management System** that allows admins to manage clients and users with different permission levels.

---

### ⚙️ Features

* 🔐 Login system for users (Admin & others)
* 👥 Manage Clients:

  * Add new client
  * Update client info
  * Delete client
  * Find client
* 💰 Transactions:

  * Deposit
  * Withdraw
  * Show total balances
* 👨‍💼 Manage Users:

  * Add / Delete / Update users
  * Assign permissions (Full / Custom)
* 🛡️ Permission system (Role-based access control)

---

### 🧠 Concepts Used

* Object-Oriented Programming (Struct-based design)
* File Handling (Read / Write / Update)
* Data Persistence using `.txt` files
* Enums for menu systems
* Separation of concerns (functions for each operation)

---

### ▶️ How to Run

1. Compile the code:

```bash
g++ Project1.cpp -o bank_system
```

2. Run:

```bash
./bank_system
```

---

## 🏧 2. ATM System

### 📌 Overview

A simulation of an **ATM machine** where users can log in using account number and PIN, then perform banking operations.

---

### ⚙️ Features

* 🔐 Login باستخدام Account Number + PIN
* 💵 Quick Withdraw (fixed amounts)
* 💸 Normal Withdraw (custom amount)
* 💰 Deposit
* 📊 Check Balance
* 🔄 Data stored in files

---

### 🧠 Concepts Used

* File Handling
* Structs & Data Modeling
* Input validation
* Menu-driven systems
* Reusable functions

---

### ▶️ How to Run

1. Compile:

```bash
g++ Project2.cpp -o atm_system
```

2. Run:

```bash
./atm_system
```

---

## 📂 Notes

* All data is stored in `.txt` files (like:

  * `ClientsData.txt`
  * `Users.txt`)
* The systems simulate real-world banking logic using console applications.

---

## 🚀 Future Improvements

* Convert project to GUI (Qt or Web)
* Add encryption for passwords
* Use database instead of text files
* Improve code structure باستخدام OOP Classes بدل Structs

---

## 👨‍💻 Author

Ahmed Zakaria
