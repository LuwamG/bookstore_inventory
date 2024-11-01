#include "book_struct.hpp" 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<Book_information> inventory; // Inventory of books
    Store_information store; // Store information

    // Set up store information
    store.name = "Local Bookstore";
    store.address = "123 Book St, Booktown";

    // Display store information
    cout << "Welcome to " << store.name << " located at " << store.address << endl;

    // Sample books to add
    Book_information book1;
    book1.title = "1984";
    book1.author.firstname = "George";
    book1.author.lastname = "Orwell";
    book1.publishdate = { 8, 6, 1949 }; // 8th June 1949

    Book_information book2;
    book2.title = "To Kill a Mockingbird";
    book2.author.firstname = "Harper";
    book2.author.lastname = "Lee";
    book2.publishdate = { 11, 7, 1960 }; // 11th July 1960

    // Adding books to inventory
    addBook(inventory, book1);
    addBook(inventory, book2);

    // Displaying current inventory
    cout << "\nCurrent Inventory:\n";
    for (const auto& book : inventory) {
        cout << book << endl;
    }

    // Searching for a book
    string searchTitle;
    cout << "\nEnter a book title to search: ";
    getline(cin, searchTitle);

    Book_information foundBook = findBook(inventory, searchTitle);
    if (foundBook.title.empty()) {
        cout << "Book not found." << endl;
    }
    else {
        cout << "Found: " << foundBook << endl;
    }

    return 0;
}
