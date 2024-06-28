# Library Management System

> This project is one of the first I created when I began learning programming in the first year of my B.Tech. I hope this project serves as a useful learning resource for those starting out in their programming journey.

A simple C++ based Library Management System that allows users to manage books and authenticate users. The system supports user login/signup, adding books, changing book status, and displaying book information based on various criteria.

### **__Features__**

    User authentication
    Add new books to the library
    Change the status of books (available, issued, removed)
    Display book information
    List books by category
    List books by author

### **File Structure**

    user.cpp: The main file containing the application logic.
    book.hpp: Header file containing functions and structures related to book management.
    authentication.hpp: Header file containing functions and structures related to user authentication.

### **Program Options**

The program provides a menu-driven interface with the following options:
    Login or Signup: Authenticate users.
    Add new book: Add a new book to the library's catalogue.
    Change book status: Update the status of a book.
    Display book information: View details of a specific book.
    List books by category: List all books in a specific category.
    List books by an author: List all books by a specific author.
    Logout: Logout the current user.
    Exit: Exit the program.

### **Code Overview**

**__user.cpp__**

    The main file of the application. It includes the logic for the user interface and calls functions defined in the other header files.

**__book.hpp__**

Contains the definitions and implementations of functions related to book management:
    insert(): Adds a new book to the library.
    
    change_status(): Changes the status of a book.
    
    display(): Displays information about a specific book.
    
    list_category(): Lists all books in a specific category.
    
    list_author(): Lists all books by a specific author.
    
    search_title(): Searches for a book by its title.
    
    search_author(): Searches for books by a specific author.
    
    search_cat(): Searches for books in a specific category.

**__authentication.hpp__**

Contains the definitions and implementations of functions related to user authentication:
    auth(): Manages user login and signup.
    
    login(): Handles user login.
    
    signup(): Handles user signup.
    
    search_details(): Searches for user credentials in the database.
