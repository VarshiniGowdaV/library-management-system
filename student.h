#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100
#define MAX_BORROWED_BOOKS 100
#define MAX_BORROWED_BOOKS_FOR_STUDENT 5


typedef struct {
    int student_id;
    char name[100];
    char department[100];
    struct {
        int book_id;
        char book_title[100];
    } borrowed_books[MAX_BORROWED_BOOKS];
    int borrowed_book_count;
} Student;

extern Student students[MAX_STUDENTS];
extern int student_count;

#endif // STUDENT_H
