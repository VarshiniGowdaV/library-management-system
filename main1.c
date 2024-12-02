#include <stdio.h>
#include "admin.h"
#include "borrowedbook.h"
#include "department.h"
#include "staff.h"
#include "sortbybookname.h"
#include "sortbyauthor.h"
#include "student.h"

// Define enums for menu options
enum MainMenuOption {
    MANAGE_BOOKS = 1,
    MANAGE_STUDENTS,
    MANAGE_DEPARTMENTS,
    MANAGE_STAFF,
    BORROWED_BOOKS,
    RETURNED_BOOKS,
    SORT_BOOKS_AUTHORS,
    EXIT_PROGRAM
};

enum BooksMenuOption {
    ADD_BOOK = 1,
    REMOVE_BOOK,
    UPDATE_BOOK,
    VIEW_BOOKS,
    BACK_TO_MAIN_MENU
};

enum BorrowedBooksMenuOption {
    RECORD_BORROWED_BOOK = 1,
    VIEW_BORROWED_BOOKS,
    BACK_TO_MAIN_MENU_BORROWED
};

void display_menu() {
    printf("\nLibrary Management Menu:\n");
    printf("1. Manage Books\n");
    printf("2. Manage Students\n");
    printf("3. Manage Departments\n");
    printf("4. Manage Staff\n");
    printf("5. Borrowed Books\n");
    printf("6. Returned Books\n");
    printf("7. Sort Books/Authors\n");
    printf("8. Exit\n");
}

void books_menu() {
    printf("\nBooks Menu:\n");
    printf("1. Add Book\n2. Remove Book\n3. Update Book\n4. View Books\n5. Back to Main Menu\n");
}

void borrowed_books_menu() {
    printf("\nBorrowed Books Menu:\n");
    printf("1. Record Borrowed Book\n2. View Borrowed Books\n3. Back to Main Menu\n");
}

void main_menu_choice(int choice) {
    int sub_choice;

    switch (choice) {
    case MANAGE_BOOKS:  // Manage Books
        do {
            books_menu();
            printf("Enter your choice: ");
            scanf("%d", &sub_choice);
            switch (sub_choice) {
            case ADD_BOOK: add_book(); break;
            case REMOVE_BOOK: remove_book(); break;
            case UPDATE_BOOK: update_book(); break;
            case VIEW_BOOKS: view_book_details(); break;
            case BACK_TO_MAIN_MENU: printf("Returning to main menu.\n"); break;
            default: printf("Invalid choice! Please try again.\n"); break;
            }
        } while (sub_choice != BACK_TO_MAIN_MENU);
        break;

    case MANAGE_STUDENTS: add_student(); break;
    case MANAGE_DEPARTMENTS: add_department(); break;
    case MANAGE_STAFF: add_staff(); break;

    case BORROWED_BOOKS:  // Borrowed Books
        do {
            borrowed_books_menu();
            printf("Enter your choice: ");
            scanf("%d", &sub_choice);
            switch (sub_choice) {
            case RECORD_BORROWED_BOOK: record_borrowed_book(); break;
            case VIEW_BORROWED_BOOKS: view_borrowed_books(); break;
            case BACK_TO_MAIN_MENU_BORROWED: printf("Returning to main menu.\n"); break;
            default: printf("Invalid choice! Please try again.\n"); break;
            }
        } while (sub_choice != BACK_TO_MAIN_MENU_BORROWED);
        break;

    case RETURNED_BOOKS: printf("Viewing returned books functionality not implemented yet.\n"); break;
    case SORT_BOOKS_AUTHORS: printf("Sorting options coming soon.\n"); break;
    case EXIT_PROGRAM: printf("Exiting program...\n"); break;

    default: printf("Invalid choice! Please enter a valid option.\n"); break;
    }

}

int main_menu() {
    if (!authenticate_admin()) {
        printf("Invalid credentials.\n");
        return 1;
    }

    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        main_menu_choice(choice);
    } while (choice != EXIT_PROGRAM);

    return 0;
}
