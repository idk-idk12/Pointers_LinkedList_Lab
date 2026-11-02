# 🔬 CMPSC 272 Lab: First Linked List Lab

Welcome to the **starting files** for the C++ **Pointers & Dynamic Memory Lab**.

This repository provides the starting point for the **First Linked List Lab**. Your challenge is to refactor an existing `Inventory` class, moving away from the `std::vector` to implement your own custom, **ordered singly linked list**. This exercise is designed to solidify your understanding of pointer manipulation and critical dynamic memory management principles in C++.

## 🎯 Project Goal

The primary objective is to convert the `Inventory` class from using a standard library container (`std::vector<Book*>`) to using a **singly linked list** built from scratch.

The linked list must correctly store pointers to `Book` objects and maintain the list in **alphabetical order by book title** at all times.

## 📁 Starter Files Overview

You have been provided with the following files. Your primary focus will be on modifying `Inventory.h` and fully implementing `Inventory.cpp` to meet the lab requirements.

| File | Description | Action Required | 
| :--- | :--- | :--- | 
| **`Book.h` & `Book.cpp`** | The definition and implementation for the `Book` class. | **No edits required.** | 
| **`main.cpp`** | Contains test logic to verify your `Inventory` class works correctly (e.g., adding, displaying, removing books). | **No edits required, but use it to test!** | 
| **`Inventory.h`** | The class declaration for `Inventory`. **You must modify this file** to remove the `std::vector` and add the required linked list components. | **Requires edits.** | 
| **`Inventory.cpp`** | The implementation file. **You must write the full implementation** for all methods here using linked list logic. | **Requires full implementation.** | 

## 🛠️ Key Implementation Tasks in `Inventory.h` / `Inventory.cpp`

You will need to introduce a private nested structure and refactor all existing methods to use pointer traversal instead of indexed access.

### 1. Define the Node Structure

In your private section of `Inventory.h`, define a struct (or class) for the linked list node:

```cpp
private:
    struct Node {
        Book* data;
        Node* next;
        Node(Book* bookPtr) : data(bookPtr), next(nullptr) {}
    };
    Node* head; // The start of your list