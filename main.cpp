/*
 * Book Inventory Management System
 * Author: [Your Name]
 * Date: [Current Date]
 * Purpose: Demonstrate the use of dynamic memory allocation and pointers
 *          with a vector-based inventory system for books.
 *
 * This program manages a collection of books using:
 * - Dynamic memory allocation for Book objects
 * - Vector of Book pointers for storage
 * - Automatic sorting by book title
 * - Proper memory management with RAII
 */

#include "Book.h"
#include "Inventory.h"
#include <iostream>
#include <string>

// Function prototypes
void demonstrateInventory();
void interactiveMenu(Inventory& inventory);
void printMenu();
Book* createBookFromInput();

int main() {
    std::cout << "=== Book Inventory Management System ===\n";
    std::cout << "Using vector of Book pointers\n\n";

    try {
        demonstrateInventory();

        // Optional: Uncomment for interactive mode
        // std::cout << "\n=== Interactive Mode ===\n";
        // Inventory userInventory;
        // interactiveMenu(userInventory);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// Function to demonstrate the inventory system
void demonstrateInventory() {
    Inventory inventory;

    std::cout << "Adding sample books to inventory...\n\n";

    // Add some books (they will be automatically sorted by title)
    inventory.addBook(new Book("The Great Gatsby", "F. Scott Fitzgerald", 12.99, 1925));
    inventory.addBook(new Book("To Kill a Mockingbird", "Harper Lee", 14.50, 1960));
    inventory.addBook(new Book("1984", "George Orwell", 13.25, 1949));
    inventory.addBook(new Book("Pride and Prejudice", "Jane Austen", 11.75, 1813));
    inventory.addBook(new Book("The Catcher in the Rye", "J.D. Salinger", 15.99, 1951));
    inventory.addBook(new Book("Animal Farm", "George Orwell", 10.50, 1945));

    // Display all books (should be in alphabetical order)
    inventory.displayAll();

    // Search for a specific book
    std::cout << "=== SEARCH DEMONSTRATION ===\n";
    std::cout << "Searching for '1984':\n";
    Book* foundBook = inventory.findBook("1984");
    if (foundBook) {
        foundBook->displayInfo();
    } else {
        std::cout << "Book not found.\n";
    }

    std::cout << "Searching for 'Nonexistent Book':\n";
    foundBook = inventory.findBook("Nonexistent Book");
    if (foundBook) {
        foundBook->displayInfo();
    } else {
        std::cout << "Book not found.\n\n";
    }

    // Remove a book
    std::cout << "=== REMOVAL DEMONSTRATION ===\n";
    inventory.removeBook("The Catcher in the Rye");
    inventory.removeBook("Nonexistent Book"); // Try to remove a book that doesn't exist

    // Display inventory after removal
    std::cout << "\nInventory after removal:\n";
    inventory.displayAll();

    std::cout << "Demonstration completed successfully!\n";
    std::cout << "Inventory destructor will automatically clean up remaining books.\n";
}

// Interactive menu for user input (optional feature)
void interactiveMenu(Inventory& inventory) {
    int choice;
    std::string title;

    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1: {
                Book* newBook = createBookFromInput();
                if (newBook) {
                    inventory.addBook(newBook);
                }
                break;
            }
            case 2:
                inventory.displayAll();
                break;
            case 3:
                std::cout << "Enter book title to search: ";
                std::getline(std::cin, title);
                {
                    Book* found = inventory.findBook(title);
                    if (found) {
                        std::cout << "\nBook found:\n";
                        found->displayInfo();
                    } else {
                        std::cout << "Book not found.\n";
                    }
                }
                break;
            case 4:
                std::cout << "Enter book title to remove: ";
                std::getline(std::cin, title);
                inventory.removeBook(title);
                break;
            case 5:
                std::cout << "Total books in inventory: " << inventory.getBookCount() << std::endl;
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << std::endl;
    } while (choice != 0);
}

void printMenu() {
    std::cout << "\n=== INVENTORY MENU ===\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Display All Books\n";
    std::cout << "3. Search for Book\n";
    std::cout << "4. Remove Book\n";
    std::cout << "5. Show Book Count\n";
    std::cout << "0. Exit\n";
}

Book* createBookFromInput() {
    std::string title, author;
    double price;
    int year;

    std::cout << "Enter book title: ";
    std::getline(std::cin, title);

    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    std::cout << "Enter price: $";
    std::cin >> price;

    std::cout << "Enter year: ";
    std::cin >> year;
    std::cin.ignore(); // Clear the input buffer

    if (price < 0 || year < 0) {
        std::cout << "Invalid input. Book not created.\n";
        return nullptr;
    }

    return new Book(title, author, price, year);
}