#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100

struct books
{
    char name[50];
    char author[50];
    int total_copies;
    int available_copies;
};

struct books library_books[MAX_BOOKS];
int book_count = 0;

void add_book()
{
    if (book_count >= MAX_BOOKS)
    {
        printf("Cannot add more books. Maximum limit reached.\n");
        return;
    }

    struct books new_book;
    printf("Enter book name: ");
    scanf(" %s", new_book.name);
    printf("Enter author name: ");
    scanf(" %s", new_book.author);
    printf("Enter total copies: ");
    scanf("%d", &new_book.total_copies);
    new_book.available_copies = new_book.total_copies;

    library_books[book_count] = new_book;
    book_count++;

    printf("Book added successfully.\n");
}
void remove_book()
{
    if (book_count == 0)
    {
        printf("No books available to remove.\n");
        return;
    }

    char book_name[50];
    printf("Enter the book name to remove: ");
    scanf(" %s", book_name);

    int found = 0;
    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(library_books[i].name, book_name) == 0)
        {
            found = 1;
            for (int j = i; j < book_count - 1; j++)
            {
                library_books[j] = library_books[j + 1];
            }
            book_count--;
            printf("Book '%s' removed successfully.\n", book_name);
            break;
        }
    }

    if (!found)
    {
        printf("Book with name '%s' not found.\n", book_name);
    }
}
void update_book()
{
    char book_name[50];
    printf("Enter the book name to update: ");
    scanf(" %s", book_name);

    int found = 0;
    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(library_books[i].name, book_name) == 0)
        {
            found = 1;

            printf("Enter new book name: ");
            scanf(" %s", library_books[i].name);
            printf("Enter new author name: ");
            scanf(" %s", library_books[i].author);
            printf("Enter new total copies: ");
            scanf("%d", &library_books[i].total_copies);
            library_books[i].available_copies = library_books[i].total_copies;
            printf("Book updated successfully.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Book with name '%s' not found.\n", book_name);
    }
}

int search_book()
{
    char book_name[50];
    printf("Enter the book name to search: ");
    scanf(" %s", book_name);

    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(library_books[i].name, book_name) == 0)
        {
            printf("Book found: '%s' by %s\n", library_books[i].name, library_books[i].author);
            printf("Total copies: %d, Available copies: %d\n", library_books[i].total_copies, library_books[i].available_copies);
            return 1;
        }
    }

    printf("Book with name '%s' not found.\n", book_name);
    return 0;
}

void view_book_details()
{
    if (book_count == 0)
    {
        printf("No books available.\n");
        return;
    }

    printf("\nList of Books:\n");
    printf("--------------------\n");
    for (int i = 0; i < book_count; i++)
    {
        printf("Book %d:\n", i + 1);
        printf("  Name: %s\n", library_books[i].name);
        printf("  Author: %s\n", library_books[i].author);
        printf("  Total copies: %d\n", library_books[i].total_copies);
        printf("  Available copies: %d\n", library_books[i].available_copies);
        printf("--------------------\n");
    }
}
void display_book_operations() {
    printf("Select a book operation:\n");
    printf("1. Add Book\n");
    printf("2. Remove Book\n");
    printf("3. Update Book\n");
    printf("4. Search Book\n");
    printf("5. View Book Details\n");
    printf("6. Sort Books by Name\n");
    printf("7. Sort Books by Author\n");
}
