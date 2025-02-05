#include "Student.h"

Student::Student(string n, int id) : Person(n, id) {}

void Student::borrowBook(Book &book) {
    if (!book.getIssuedStatus()) {
        book.issueBook();
        borrowedBooks.push_back(&book);
    } else {
        cout << book.getTitle() << " is not available.\n";
    }
}

void Student::returnBook(Book &book) {
    book.returnBook();
}

void Student::showInfo() {
    cout << "Student Name: " << name << ", ID: " << personID << "\n";
}
