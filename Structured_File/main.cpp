#include "Book.h"
#include "Student.h"
#include "Librarian.h"
#include "Constant.h"
#include <vector>

int main() {
    vector<Book> library;
    library.push_back(Book("C++ Programming", "Bjarne Stroustrup", 101));
    library.push_back(Book("Data Structures", "Mark Allen Weiss", 102));

    Librarian librarian("Mr. Smith", 1);
    librarian.showInfo();
    librarian.addBook(library, "Design Patterns", "GoF", 103);

    Student student("Alice", 202);
    student.showInfo();

    student.borrowBook(library[0]);
    student.borrowBook(library[1]);

    student.returnBook(library[0]);

    return 0;
}
