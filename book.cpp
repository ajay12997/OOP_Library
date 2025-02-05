#include "Book.h"
#include "constant.h"  // Use of constants

// Constructor
Book::Book(string t, string a, int id) : title(t), author(a), bookID(id), isIssued(false) {
    bookCounter++;  
}

void Book::issueBook() {
    if (!isIssued) {
        isIssued = true;
        cout << title << " has been issued successfully.\n";
    } else {
        cout << title << " is already issued.\n";
    }
}

void Book::returnBook() {
    if (isIssued) {
        isIssued = false;
        cout << "✅ " << title << " has been returned successfully.\n";
    }
}

string Book::getTitle() { return title; }

bool Book::getIssuedStatus() { return isIssued; }
