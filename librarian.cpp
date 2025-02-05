#include "Librarian.h"

Librarian::Librarian(string n, int id) : Person(n, id) {}

void Librarian::addBook(vector<Book> &library, string title, string author, int id) {
    library.push_back(Book(title, author, id));
    cout << title << " added to the library.\n";
}

void Librarian::showInfo() {
    cout << "Librarian Name: " << name << ", ID: " << personID << "\n";
}
