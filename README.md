# Student Management System in C

📖 Overview
The Student Management System is a lightweight, console-based application designed to manage student academic data efficiently. This project was developed as a foundational exercise in C programming, focusing on data structure organization and persistent file storage. By utilizing file streams, the application allows users to create, read, and search for records, ensuring data remains available even after the application is terminated.

🛠 Technical Stack
Language: C (C99 standard or higher)

Core Concepts: * struct (Data Encapsulation)

FILE I/O (Data Persistence)

Switch-Case (Control Flow)

Modular Programming (Functions)

🚀 Key Features
1. Data Persistence
Unlike programs that store data in volatile memory (RAM), this system saves all student information into a local students.txt file. This means your data survives system restarts.

2. Formatted Reporting
The system uses standard output formatting (\t tab characters) to present data in a clean, readable, table-like format for easy inspection.

3. Efficient Searching
The search algorithm performs a sequential scan of the text file. It parses the stored strings and integers, compares them against user input, and returns specific details immediately upon a successful match.

⚙️ How to Build and Run

 Prerequisites


1. A C Compiler (GCC recommended).

2. Terminal or Command Prompt access.

💡 Future Enhancements

This project serves as a starting point. Possible areas for further development include:

Sorting: Implementing a sorting algorithm (like Bubble Sort) to order students by marks.

Deletion: Adding functionality to remove specific student records from the file.

Data Validation: Implementing checks to ensure names contain only letters and marks are between 0 and 100.
