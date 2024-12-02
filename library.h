#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>

// Declare the MainMenuOption enum
typedef enum {
    MAIN_BOOK_OPERATIONS = 1,
    MAIN_STUDENT_OPERATIONS,
    MAIN_DEPARTMENT_OPERATIONS,
    MAIN_STAFF_OPERATIONS,
    MAIN_BORROWED_OPERATIONS,
    EXIT_OPTION
} MainMenuOption;

// Function declaration for handle_choice
void handle_choice(MainMenuOption choice);

// Other function declarations for operations (book, student, etc.)
// Example:
// void book_operations();
// void student_operations();

#endif // LIBRARY_H
