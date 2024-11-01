#ifndef BOOK_STRUCT_HPP
#define BOOK_STRUCT_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Book_information {
    string title;

    struct Author {
       string firstname;
       string lastname;
    };

    struct Publishdate {
        int day;
        int month;
        int year;
    };

    Author author;
    Publishdate publishdate;

    // Overloading the equality operator to check if a book matches by title
    bool operator==(const string& searchTitle) const {
        return title == searchTitle;
    }
};

// Overloading the output operator for Book_information
ostream& operator<<(ostream& stream, const Book_information& book);

// Function declarations
void addBook(vector<Book_information>& inventory, const Book_information& book);
Book_information findBook(const vector<Book_information>& inventory, const string& title);

#endif // BOOK_STRUCT_HPP
