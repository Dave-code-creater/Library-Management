#include <iostream>
#include "LibraryManage.h"

Book::Book(std::string title, std::string author, std::string ISBN, std::string genre, int price, bool available)
    : _title(title), _author(author), _ISBN(ISBN), _genre(genre), _price(price), _available(available) {}

void Book::setTitle(std::string title) {
    _title = title;
}
void Book::setAuthor(std::string author) {
    _author = author;
}
void Book::setISBN(std::string ISBN) {
    _ISBN = ISBN;
}
void Book::setGenre(std::string genre) {
    _genre = genre;
}
void Book::setPrice(int price) {
    if (price <= 0) {
        std::cerr << "Error: The price of this book cannot be negative. Setting it back to 0";
        _price = 0;
    } else {
        _price = price;
    }
}
void Book::setAvailable(bool available) {
    _available = available;
}

std::string Book::getTitle() const {
    return _title;
}
std::string Book::getAuthor() const {
    return _author;
}
std::string Book::getISBN() const {
    return _ISBN;
}
std::string Book::getGenre() const {
    return _genre;
}
int Book::getPrice() const {
    return _price;
}
bool Book::getAvailable() const {
    return _available;
}

void Book::displayInformation() const {
    std::cout << "Information about the book:" << std::endl;
    std::cout << "Title: " << _title << std::endl;
    std::cout << "Author: " << _author << std::endl;
    std::cout << "ISBN: " << _ISBN << std::endl;
    std::cout << "Genre: " << _genre << std::endl;
    std::cout << "Price: " << _price << " $" << std::endl;
    std::cout << "Availability: " << (_available ? "Available" : "Unavailable") << std::endl;
}
