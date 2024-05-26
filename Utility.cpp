#include <iostream>
#include "LibraryManage.h"

void DisplayMenu(Library& library) {
    int repeat = 1;
    char option;

    do {
        std::cout << "\t\t\tWelcome to our library!" << std::endl;
        std::cout << "\t\t\tIt allows users to perform basic operations such as adding, deleting, and searching for books in a library database.\n";
        std::cout << "1. Donate a book to the library." << std::endl;
        std::cout << "2. Borrow books." << std::endl;
        std::cout << "3. Create an account." << std::endl;
        std::cout << "4. Return a book." << std::endl;
        std::cout << "5. Search for your favorite book." << std::endl;
        std::cout << "6. Exit." << std::endl;
        std::cout << "What is your option: ";
        std::cin >> option;

        switch (option) {
            case '1':
                library.addBook();
                break;
            case '2':
                library.displayAllBooks();
                library.borrowBooks();
                break;
            case '3':
                library.addAccount();
                break;
            case '4': {
                std::string ISBN;
                std::cout << "Enter ISBN of the book to return: ";
                std::cin >> ISBN;
                library.returnBook(ISBN);
                break;
            }
            case '5': {
                std::string title;
                std::cout << "Enter the title of the book: ";
                std::cin >> title;
                library.searchBook(title);
                break;
            }
            case '6':
                repeat = 0;
                break;
            default:
                std::cerr << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (repeat == 1);
    std::cout << "Thank you for using our program" << std::endl;
}
