# Bank Management System (C++ & OOP)

A robust, console-based Bank Management System built with **C++** using pure **Object-Oriented Programming (OOP)** principles. This project simulates a real-world banking environment, featuring multi-user access control, client transaction management, currency exchange, and persistent data storage.

This project was developed as a final application for the **"OOP as it Should Be"** curriculum, focusing on modularity, inheritance, and clean code architecture.

## 🚀 Key Features

### 1. Client Management
* **CRUD Operations:** Full capability to Add, Delete, Update, and Find clients.
* **Data Validation:** Integrated input validation to ensure data integrity (e.g., account numbers, pin codes).

### 2. Transaction Management
* **Financial Operations:** Securely handle Deposits and Withdrawals.
* **Internal Transfers:** Transfer funds between accounts with real-time balance updates.
* **Total Balances:** Generate reports on the total liquidity within the bank.
* **Transfer Logs:** A dedicated logging system to track every transaction for auditing.

### 3. User & Security System
* **Authentication:** Secure Login/Logout system with encrypted passwords.
* **Permissions System:** Role-based access control (RBAC). Specific users can be restricted from sensitive screens (e.g., managing users or viewing logs).
* **Login Register:** Automatically logs every login attempt with timestamps and user details.

### 4. Currency Exchange
* **Real-time Conversion:** Update exchange rates and calculate conversions between different currencies.
* **Currency Database:** Search and list global currencies stored in the system.

## 🛠️ Technical Implementation (OOP Concepts)

The system is designed with a high degree of abstraction and modularity:

* **Inheritance:** Utilizes a base `clsScreen` class from which all UI screens inherit, ensuring a consistent look and feel.
* **Encapsulation:** Data is protected within classes (e.g., `clsBankClient`, `clsUser`) using private members and public static methods for data handling.
* **Abstraction:** Complex file handling and data parsing logic are hidden behind simple method calls.
* **Static Methods & Classes:** Heavy use of utility classes like `clsString`, `clsDate`, and `clsInputValidate` for reusable logic across the project.
* **File-Based Database:** Implements a simulation of a database using `.txt` files with automated parsing and saving.

## 💻 Tech Stack
* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Data Storage:** Text-file persistence (`Clients.txt`, `Users.txt`, `Currencies.txt`)
* **Architecture:** Layered architecture (UI Layer, Business Logic Layer, Data Access Layer)

## 📂 Project Structure
The project is segmented into logical headers for better maintainability:
* `Core/`: Contains the main business entities (`clsBankClient`, `clsUser`, `clsCurrency`).
* `Screens/`: Contains the UI logic for every menu and sub-menu.
* `Lib/`: Utility libraries for strings, dates, and input validation.

## ⚙️ How to Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/MohamedOSorour/Bank-System-Full-Version-OOP-.git](https://github.com/MohamedOSorour/Bank-System-Full-Version-OOP-.git)
    ```
2.  Open the project in any C++ supported IDE (Visual Studio, Code::Blocks, or CLion).
3.  Ensure the `.txt` data files are in the same directory as the executable.
4.  Compile and run `main.cpp`.