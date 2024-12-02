#include <stdio.h>
#include <string.h>
#include "returnedbook.h"

#define MAX_BOOKS 100

struct returned_book returned_books[MAX_BOOKS];
int current_book_count = 0;

int record_returned_book()
{
    if (current_book_count >= MAX_BOOKS)
    {
        printf("Error: Maximum number of returned books reached.\n");
        return -1;
    }

    struct returned_book new_book;
    printf("Enter student name: ");
    fgets(new_book.student_name, sizeof(new_book.student_name), stdin);
    new_book.student_name[strcspn(new_book.student_name, "\n")] = '\0';

    printf("Enter student USN: ");
    fgets(new_book.usn, sizeof(new_book.usn), stdin);
    new_book.usn[strcspn(new_book.usn, "\n")] = '\0';

    printf("Enter department: ");
    fgets(new_book.dept, sizeof(new_book.dept), stdin);
    new_book.dept[strcspn(new_book.dept, "\n")] = '\0';

    printf("Enter book name: ");
    fgets(new_book.book_name, sizeof(new_book.book_name), stdin);
    new_book.book_name[strcspn(new_book.book_name, "\n")] = '\0';

    printf("Enter return date (DD/MM/YYYY): ");
    fgets(new_book.return_date, sizeof(new_book.return_date), stdin);
    new_book.return_date[strcspn(new_book.return_date, "\n")] = '\0';
    returned_books[current_book_count++] = new_book;

    printf("Book return recorded successfully.\n");
    return 0;
}

void view_returned_books()
{
    if (current_book_count == 0)
    {
        printf("No books have been returned yet.\n");
        return;
    }
    printf("\nList of returned books:\n");
    printf("Student Name | USN | Department | Book Name | Return Date\n");
    for (int i = 0; i < current_book_count; i++)
    {
        printf("%s | %s | %s | %s | %s\n",
               returned_books[i].student_name,
               returned_books[i].usn,
               returned_books[i].dept,
               returned_books[i].book_name,
               returned_books[i].return_date);
    }
}
