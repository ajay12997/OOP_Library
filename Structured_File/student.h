#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Book.h"
#include <vector>

class Student : public Person {
private:
    vector<Book*> borrowedBooks;

public:
    Student(string n, int id);
    void borrowBook(Book &book);
    void returnBook(Book &book);
    void showInfo() override;
};

#endif 

