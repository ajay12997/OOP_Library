#define BOOK_H

#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int bookID;
    bool isIssued;

public:
    Book(string t, string a, int id);
    void issueBook();
    void returnBook();
    string getTitle();
    bool getIssuedStatus();
};
