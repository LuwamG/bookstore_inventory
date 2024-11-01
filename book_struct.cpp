#include "book_struct.hpp"
using namespace std;
// Overloading the output operator for Book_information
ostream& operator<<(ostream& stream, const Book_information& book) {
    stream << "Title: " << book.title
        << ", Author: " << book.author.firstname << " " << book.author.lastname
        << ", Published on: " << book.publishdate.day << "/"
        << book.publishdate.month << "/" << book.publishdate.year;
    return stream;
}

void addBook(vector<Book_information>& inventory, const Book_information& book) {
    inventory.push_back(book);
}

Book_information findBook(const vector<Book_information>& inventory, const string& title) {
    for (const auto& book : inventory) {
        if (book.title == title) {
            return book;
        }
    }
    return {}; 
}
