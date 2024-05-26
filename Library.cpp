#include <iostream>
#include "LibraryManage.h"

void Library::addBook() {
    std::string title, author, ISBN, genre;
    int price;
    bool available = true;

    std::cout << "Enter book title: ";
    std::cin.ignore(); 
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter book ISBN: ";
    std::getline(std::cin, ISBN);
    std::cout << "Enter book genre: ";
    std::getline(std::cin, genre);
    std::cout << "Enter book price: ";
    std::cin >> price;

    Book newBook(title, author, ISBN, genre, price, available);
    books.push_back(newBook);

    std::cout << "Book added successfully!" << std::endl;
}

// Function to return a borrowed book to the library
void Library::returnBook(const std::string& ISBN) {
    for (auto& book : books) {
        if (book.getISBN() == ISBN && !book.getAvailable()) {
            book.setAvailable(true);
            std::cout << "Book returned successfully!" << std::endl;
            return;
        }
    }
    std::cerr << "Error: Book with ISBN " << ISBN << " not found or already available." << std::endl;
}

// Function to borrow a book from the library
void Library::borrowBooks() {
    std::string username, password, ISBN;

    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    if (!checkInformation(username, password)) {
        return;
    }

    std::cout << "Enter the ISBN of the book you want to borrow: ";
    std::cin >> ISBN;

    for (auto& book : books) {
        if (book.getISBN() == ISBN) {
            if (book.getAvailable()) {
                book.setAvailable(false);
                for (auto& user : users) {
                    if (user.getUsername() == username) {
                        user.borrowBook(book);
                        std::cout << "Book borrowed successfully!" << std::endl;
                        return;
                    }
                }
            } else {
                std::cerr << "Error: Book is not available." << std::endl;
                return;
            }
        }
    }
    std::cerr << "Error: Book with ISBN " << ISBN << " not found." << std::endl;
}

// Function to search for a book by title
Book* Library::searchBook(const std::string& title) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            book.displayInformation();
            return &book;
        }
    }
    std::cerr << "Error: Book with title " << title << " not found." << std::endl;
    return nullptr;
}

void Library::displayAllBooks() const {
    for (const auto& book : books) {
        book.displayInformation();
    }
}

void Library::addAccount() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    if (userExists(username)) {
        std::cerr << "Error: Username already exists." << std::endl;
        return;
    }
    users.emplace_back(username, password);
}

bool Library::userExists(const std::string& username) const {
    for (const auto& user : users) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool Library::checkInformation(std::string& username, std::string& password) {
    for (const auto& user : users) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }
    std::cerr << "Error: Username or password is incorrect." << std::endl;
    return false;
}
