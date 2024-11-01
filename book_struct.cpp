#include "book_struct.hpp"
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
	//friend ostream& operator<<(ostream& stream, const Book_information& book);

	// Overloading the equality operator to check if a book matches by title
	bool operator==(const string& searchTitle) const {
		return title == searchTitle;
	}
};
ostream& operator<<(ostream& stream, const Book_information& book) {
	stream << "Title: " << book.title
		<< ", Author: " << book.author.firstname << " " << book.author.lastname
		<< ", Published on: " << book.publishdate.day << "/"
		<< book.publishdate.month << "/" << book.publishdate.year;
	return stream;
}
struct Store_information {
	string name;
	string address;
};
void addBook(vector<Book_information>& inventory, const Book_information& book) {
	inventory.push_back(book);
}
Book_information findBook(vector<Book_information>& inventory, const string& title) {
	for (auto& book : inventory) {
		if (book.title == title) {
			return book;
		}
	}
}