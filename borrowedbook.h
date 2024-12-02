#ifndef BORROWEDBOOK_H
#define BORROWEDBOOK_H
#define MAX_BORROWED_BOOKS 100
#define MAX_BORROWED_BOOKS_FOR_BORROWED_BOOK 100

struct borrowedbook
{
    char student_name_[50];
    char usn[50];
    char book_name[50];
    char borrow_date[20];
};
// int record_borrowed_book();
// void view_borrowed_books();
// int record_borrowed_book();
// int record_borrowed_book();
void record_borrowed_book(void);
void view_borrowed_books(void);
void view_returned_books(void);
#endif // BORROWEDBOOK_H
