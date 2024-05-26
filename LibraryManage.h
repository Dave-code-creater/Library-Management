#pragma once
#ifndef LIBRARY_MANAGEMENT_H
#define LIBRARY_MANAGEMENT_H

#include <string>
#include <vector>

#define MAX_NUMBER_OF_BOOKS 10

class Book {
private:
    std::string _title;
    std::string _author;
    std::string _ISBN;
    std::string _genre;
    int _price;
    bool _available = false;

public:
    // Constructor
    Book(std::string title, std::string author, std::string ISBN, std::string genre, int price, bool available = false);

    // Setters
    void setTitle(std::string title);
    void setAuthor(std::string author);
    void setISBN(std::string ISBN);
    void setGenre(std::string genre);
    void setPrice(int price);
    void setAvailable(bool available);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    std::string getGenre() const;
    int getPrice() const;
    bool getAvailable() const;

    // Function
    void displayInformation() const;
};

class User {
private:
    std::string _username;
    std::string _password;
    std::vector<Book> _borrowedBooks;

public:
    // Constructor
    User(std::string username, std::string password);

    // Setters
    void setUsername(std::string username);
    void setPassword(std::string password);

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;

    // Methods for user interactions with the library
    void borrowBook(Book& book);
    void returnBook(std::string ISBN);
    void displayInformation() const;
};

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    // Methods for managing books in the library
    void addBook();
    void returnBook(const std::string& ISBN);
    void borrowBooks();
    Book* searchBook(const std::string& title);
    void displayAllBooks() const;
    void addAccount();
    bool userExists(const std::string& username) const;
    bool checkInformation(std::string& username, std::string& password);
};

void DisplayMenu(Library& library);

#endif
