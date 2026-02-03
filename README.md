🏦 Bank Management System (C++ Console App)

A simple Bank Management System implemented in C++ that allows managing customer accounts with basic operations such as creating accounts, viewing records, updating, searching, transactions (deposit/withdraw), and deleting accounts.

This is a beginner-friendly console application suitable for learning object-oriented programming and file-free data management in C++.

📌 Features

Create new customer accounts

View all customers and their details

Update existing accounts

Search for a specific account by ID

Perform transactions (deposit & withdraw)

Delete customer accounts

Data stored in memory (no database)

🛠️ Getting Started
📋 Prerequisites

Ensure you have a C++ compiler installed:

GCC / G++

Clang

MS Visual C++ (MSVC)

📥 How to Compile & Run

From the terminal (Linux/macOS) or Command Prompt / PowerShell (Windows):

g++ -o bank_app main.cpp
./bank_app


Or using another compiler of your choice.

📁 Code Structure
Bank Management System
├── main.cpp
└── README.md


main.cpp – Contains all the code (Bank class and menu logic).

README.md – Project documentation.

🚀 Usage

When you run the program, a menu appears with options:

1. Create new account
2. View all customers
3. Update account
4. Search account
5. Transaction
6. Delete account
7. Exit


Just enter the number of the option you want to perform and follow the prompts in the console.

📌 Example Interactions

✔ Create an account with name, ID, contact, cash
✔ Deposit or withdraw money from an account
✔ Search or update accounts using an ID

🧠 How It Works

Data is stored in an array inside the Bank class (supports up to 100 accounts).

Each account has a name, ID, address, contact, and cash balance.

The system loops through the menu until the user chooses to exit.

❗ Limitations

📍 This version:

Doesn’t save data to a file or database

Keeps all data in memory (lost on exit)

Has a fixed maximum of 100 accounts

You can extend it later with file storage or dynamic containers like vector.

📌 Contributing

Feel free to:

Add file I/O support

Use STL containers (vector, map)

Implement authentication and better error handling

📜 License

This project is open and free to use for learning and educational purposes.

❤️ Acknowledgements

Thanks to all the open-source README templates and guides that helped structure this documentation.
