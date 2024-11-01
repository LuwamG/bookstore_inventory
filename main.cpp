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
    cout << "Enter book title: ";
    cin >> book1.title;
    cin.ignore();
    cout << "Enter author's first name: ";
    cin >> book1.author.firstname ;
    cin.ignore();
    cout << "Enter author's last name: ";
    cin >>book1.author.lastname;
    cin.ignore();
    cout <<"Enter publish date: ";
    cin >> book1.publishdate.day;
    cin.ignore();

    Book_information book2;
    cout << "Enter book2 title: ";
    cin >> book2.title;
    cin.ignore();
    cout << "Enter author's first name: ";
    cin >> book2.author.firstname;
    cin.ignore();
    cout << "Enter author's last name: ";
    cin >> book2.author.lastname;
    cin.ignore();
    cout << "Enter publish date: ";
    cin >> book2.publishdate.day;
    cin.ignore();


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
