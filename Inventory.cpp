#include "Inventory.h"
#include <iostream>
#include <algorithm>

// Constructor
Inventory::Inventory() : head(nullptr) {}

// Destructor - Important! Clean up dynamically allocated memory
Inventory::~Inventory() {
    // Delete all Book objects to prevent memory leaks
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        delete curr->data;  // frees the book object
        delete curr;        // frees the node object
        curr = nextNode;
    }
    head = nullptr;
}

// Add a book to the inventory (sorted by title alphabetically)
void Inventory::addBook(Book* bookPtr) {
    if (bookPtr == nullptr) {
        std::cout << "Error: Cannot add null book pointer.\n";
        return;
    }

    Node* newNode = new Node(bookPtr);
    // handles the case of empty list and if the book's title should come before the current head.
    if (head == nullptr || bookPtr->getTitle() < head->data->getTitle()) {
        newNode->next = head;
        head = newNode;
    }
    // handles the case in which it has to iterate over the linked list.
    else {
        Node* curr = head;
        // if curr->next == nullptr, that means we have reached the end of the list and we'll add the new node at the end.
        // if bookPtr->getTitle < curr->next->data->getTitle(), then we'll insert the new node AFTER the curr node.
        while (curr->next != nullptr && bookPtr->getTitle() >= curr->next->data->getTitle()) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    std::cout << "Book '" << bookPtr->getTitle() << "' added to inventory.\n";
}

// Display all books in the inventory
void Inventory::displayAll() const {
    if (this->isEmpty()) {
        std::cout << "No books in inventory.\n";
        return;
    }

    std::cout << "\n=== INVENTORY CONTENTS ===\n";
    std::cout << "Total books: " << this->getBookCount() << "\n\n";

    int i = 0;
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << "Book #" << (i + 1) << ":\n";
        curr->data->displayInfo();
        curr = curr->next;
    }
    std::cout << "\n";
}

// Remove a book by title
void Inventory::removeBook(const std::string& title) {
    Node* previous;
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data->getTitle() == title) {
            // this means that we'd want to remove the head pointer.
            if (previous == nullptr) {
                head = curr->next;
            }
            else {
                previous->next = curr->next;
            }
            // deletes curr pointer
            std::cout << "Removing book: " << curr->data->getTitle() << "\n";
            delete curr->data;
            delete curr;
            return;
        }
        previous = curr;
        curr = curr->next;
    }
    std::cout << "Book '" << title << "' not found in inventory.\n";
}

// Get the number of books
size_t Inventory::getBookCount() const {
    size_t totalBooks = 0;
    Node* curr = head;
    while (curr) {
        totalBooks += 1;
        curr = curr->next;
    }
    return totalBooks;
}

// Search for a book by title
Book* Inventory::findBook(const std::string& title) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data->getTitle() == title) {
            return curr->data;
        }
        curr = curr->next;
    }
    return nullptr;
}

// Check if inventory is empty
bool Inventory::isEmpty() const {
    return head == nullptr;
}