#ifndef INVENTORY_H
#define INVENTORY_H

#include "Book.h"
#include <vector>
#include <string>
#include <cstddef> // For size_t


class Inventory {
private:
    struct Node {
        Book* data;  // data is a book pointer
        Node* next;  // next is a node pointer
        Node(Book* bookPtr) : data(bookPtr), next(nullptr) {}  // struct's constructor
    };
    Node* head;

public:

    // Constructor
    // Pseudocode: Initialize the 'books' vector to be empty.
    Inventory();

    // Destructor - Clean up dynamically allocated memory
    // Pseudocode: Iterate through all elements in the 'books' vector. For each
    // 'Book*' pointer, call 'delete' to free the memory.
    ~Inventory();

    // Copy constructor and assignment operator (deleted to prevent shallow copying)
    Inventory(const Inventory& other) = delete;
    Inventory& operator=(const Inventory& other) = delete;

    // Add a book to the inventory (sorted by title alphabetically)
    // Pseudocode: 1. Check if 'bookPtr' is valid. 2. Iterate through the 'books'
    // vector to find the correct sorted insertion point (alphabetically by title).
    // 3. Insert 'bookPtr' at that position.
    void addBook(Book* bookPtr);

    // Display all books in the inventory
    // Pseudocode: 1. Check if the inventory is empty. 2. If not empty,
    // iterate through the 'books' vector. 3. For each 'Book*' pointer, call its display method.
    void displayAll() const;

    // Remove a book by title
    // Pseudocode: 1. Iterate through the 'books' vector. 2. When a book with a
    // matching 'title' is found: a) Delete the 'Book*' pointer to free memory.
    // b) Remove the pointer from the 'books' vector. 3. Stop and return (assuming only one match).
    void removeBook(const std::string& title);

    // Get the number of books
    // Pseudocode: Return the current number of elements (size) in the 'books' vector.
    size_t getBookCount() const;

    // Search for a book by title
    // Pseudocode: 1. Iterate through the 'books' vector. 2. If a book's title
    // matches the input 'title', return the 'Book*' pointer. 3. If no match is found, return 'nullptr'.
    Book* findBook(const std::string& title) const;

    // Check if inventory is empty
    // Pseudocode: Return 'true' if the size of the 'books' vector is 0; otherwise, return 'false'.
    bool isEmpty() const;
};

#endif // INVENTORY_H
