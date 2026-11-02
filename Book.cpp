#include "Book.h"
#include <iostream>

// Constructor
Book::Book(const std::string& title, const std::string& author, double price, int year)
    : title(title), author(author), price(price), year(year) {}

// Getter methods
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

double Book::getPrice() const {
    return price;
}

int Book::getYear() const {
    return year;
}

// Method to display book information
void Book::displayInfo() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Price: $" << price << "\n"
              << "Year: " << year << "\n"
              << "------------------------\n";
}