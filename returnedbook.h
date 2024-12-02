#ifndef RETURNEDBOOK_H
#define RETURNEDBOOK_H

struct returned_book {
    char student_name[100];
    char usn[20];
    char dept[50];
    char book_name[100];
    char return_date[20];
};

// Function declarations
int record_returned_book();
void view_returned_books();

#endif // RETURNEDBOOK_H
