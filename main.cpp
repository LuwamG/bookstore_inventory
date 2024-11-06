#include "book_struct.hpp" 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<Book_information> inventory; 
    Store_information store; 

    // Set up store information
    cout << "Enter store name: ";
    getline(cin,store.name) ;
    cin.ignore();
    cout << "Enter store address: ";
    getline(cin,store.address);
    cin.ignore();

    // Display store information
    cout << "Welcome to " << store.name << " located at " << store.address << endl;

    // Sample books to add
    Book_information book1;
    cout << "Enter book title: ";
    getline(cin, book1.title);
    cin.ignore();
    cout << "Enter author's first name: ";
    getline(cin, book1.author.firstname);
    cin.ignore();
    cout << "Enter author's last name: ";
    getline(cin,book1.author.lastname);
    cin.ignore();
    cout <<"Enter publish date(day/month/year): ";
    cin >> book1.publishdate.day >> book1.publishdate.month >> book1.publishdate.year;
    cin.ignore();

    Book_information book2;
    cout << "Enter book2 title: ";
    getline(cin, book2.title);
    cin.ignore();
    cout << "Enter author's first name: ";
    getline(cin, book2.author.firstname);
    cin.ignore();
    cout << "Enter author's last name: ";
    getline(cin, book2.author.lastname);
    cin.ignore();
    cout << "Enter publish date(day/month/year): ";
    cin >> book2.publishdate.day >> book2.publishdate.month >> book2.publishdate.year;
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
