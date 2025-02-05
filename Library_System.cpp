#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;

///// BASE CLASS (Encapsulation & Abstraction) /////
class Book {
private:
    string title;
    string author;
    int bookID;
    bool isIssued;

public:
    // Constructor
    Book(string t, string a, int id) : title(t), author(a), bookID(id), isIssued(false) {}

    // Getter Methods (Encapsulation)
    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getBookID() { return bookID; }
    bool getIssuedStatus() { return isIssued; }

    // Issue Book
    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << title << " has been issued successfully.\n";
        } else {
            cout << title << " is already issued.\n";
        }
    }

    // Return Book
    void returnBook() {
        if (isIssued) {
            isIssued = false;
            cout << title << " has been returned successfully.\n";
        } else {
            cout << title << " was not issued.\n";
        }
    }
};

///// BASE CLASS (Person) /////
class Person {
protected:
    string name;
    int personID;

public:
    Person(string n, int id) : name(n), personID(id) {}

    virtual void showInfo() = 0; // Pure Virtual Function (Abstraction)
};

///// DERIVED CLASS (Inheritance) /////
class Student : public Person {
private:
    vector<Book*> borrowedBooks; // Aggregation

public:
    Student(string n, int id) : Person(n, id) {}

    void borrowBook(Book &book) {
        if (!book.getIssuedStatus()) {
            book.issueBook();
            borrowedBooks.push_back(&book);
        } else {
            cout<< book.getTitle() << " is not available.\n";
        }
    }

    void returnBook(Book &book) {
        book.returnBook();
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), &book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
        }
    }

    void showInfo() override {  // Function Overriding (Polymorphism)
        cout << "Student Name: " << name << ", ID: " << personID << "\n";
    }
};

///// DERIVED CLASS (Librarian) /////
class Librarian : public Person {
public:
    Librarian(string n, int id) : Person(n, id) {}

    void addBook(vector<Book> &library, string title, string author, int id) {
        library.push_back(Book(title, author, id));
        cout << title << " added to the library.\n";
    }

    void showInfo() override {  // Function Overriding (Polymorphism)
        cout << "Librarian Name: " << name << ", ID: " << personID << "\n";
    }
};

///// MAIN FUNCTION /////
int main() {
    // Book Collection
    vector<Book> library;
    library.push_back(Book("C++ Programming", "Bjarne Stroustrup", 101));
    library.push_back(Book("Data Structures", "Mark Allen Weiss", 102));

    // Librarian
    Librarian librarian("Mr. Prem", 1);
    librarian.showInfo();

    // Adding a new book
    librarian.addBook(library, "Design Patterns", "GoF", 103);

    // Student
    Student student("Ajay", 202);
    student.showInfo();

    // Borrowing Books
    student.borrowBook(library[0]);  // Borrow "C++ Programming"
    student.borrowBook(library[1]);  // Borrow "Data Structures"

    // Returning Books
    student.returnBook(library[0]);  // Return "C++ Programming"

    return 0;
}