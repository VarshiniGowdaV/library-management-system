#ifndef BOOKS_H
#define BOOKS_H
#define MAX_BOOKS 100
struct books
{
    char name[50];
    int id;
    char title[100];
    char author[100];
    int year;
    int total_copies;
    int available_copies;
};
extern struct books library_books[MAX_BOOKS];
extern int book_count;
void add_book();
void remove_book();
void update_book();
int search_book();
void view_book_details();

#endif // BOOKS_H


