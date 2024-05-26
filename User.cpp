#include <iostream>
#include "LibraryManage.h"

User::User(std::string username, std::string password)
    : _username(username), _password(password) {}

void User::setUsername(std::string username) {
    _username = username;
}

void User::setPassword(std::string password) {
    _password = password;
}

std::string User::getUsername() const {
    return _username;
}

std::string User::getPassword() const {
    return _password;
}

void User::borrowBook(Book& book) {
    _borrowedBooks.push_back(book);
    book.setAvailable(false);
}

void User::returnBook(std::string ISBN) {
    for (size_t i = 0; i < _borrowedBooks.size(); ++i) {
        if (_borrowedBooks[i].getISBN() == ISBN) {
            _borrowedBooks[i].setAvailable(true);
            _borrowedBooks.erase(_borrowedBooks.begin() + i);
            return;
        }
    }
    std::cerr << "Error: Book with ISBN " << ISBN << " not found in the list of borrowed books." << std::endl;
}

void User::displayInformation() const {
    std::cout << "User Information:" << std::endl;
    std::cout << "Username: " << _username << std::endl;
    std::cout << "Number of Borrowed Books: " << _borrowedBooks.size() << std::endl;
    if (!_borrowedBooks.empty()) {
        std::cout << "Borrowed Books:" << std::endl;
        for (const auto& book : _borrowedBooks) {
            book.displayInformation();
            std::cout << std::endl;
        }
    }
}
