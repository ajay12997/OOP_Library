#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"
#include "Book.h"
#include <vector>

class Librarian : public Person {
public:
    Librarian(string n, int id);
    void addBook(vector<Book> &library, string title, string author, int id);
    void showInfo() override;
};

#endif // LIBRARIAN_H

