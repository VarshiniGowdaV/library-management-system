#include "student.h"
#include <stdio.h>
#include <string.h>

Student students[MAX_STUDENTS];
int student_count = 0;

// Function to add a student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students, the student list is full.\n");
        return;
    }

    Student new_student;

    printf("Enter student ID: ");
    scanf("%d", &new_student.student_id);

    getchar();

    printf("Enter student name: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0';

    printf("Enter student department: ");
    fgets(new_student.department, sizeof(new_student.department), stdin);
    new_student.department[strcspn(new_student.department, "\n")] = '\0';

    new_student.borrowed_book_count = 0;

    students[student_count++] = new_student;
    printf("Student added successfully.\n");
}
void update_student() {
    int id, found = 0;

    printf("Enter student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == id) {
            found = 1;

            getchar();

            printf("Enter new student name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter new student department: ");
            fgets(students[i].department, sizeof(students[i].department), stdin);
            students[i].department[strcspn(students[i].department, "\n")] = '\0';

            printf("Student updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}
void view_student() {
    if (student_count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("Student List:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, Department: %s\n", students[i].student_id, students[i].name, students[i].department);
    }
}
void borrow_book_by_student() {
    int student_id, book_id;
    char book_title[100];
    int found = 0;

    printf("Enter student ID: ");
    scanf("%d", &student_id);

    printf("Enter book ID: ");
    scanf("%d", &book_id);

    getchar();

    printf("Enter book title: ");
    fgets(book_title, sizeof(book_title), stdin);
    book_title[strcspn(book_title, "\n")] = '\0';
    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == student_id) {
            found = 1;
            if (students[i].borrowed_book_count < MAX_BORROWED_BOOKS) {
                students[i].borrowed_books[students[i].borrowed_book_count].book_id = book_id;
                strcpy(students[i].borrowed_books[students[i].borrowed_book_count].book_title, book_title);
                students[i].borrowed_book_count++;
                printf("Book borrowed successfully.\n");
            } else {
                printf("Student has already borrowed the maximum number of books.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", student_id);
    }
}
void view_student_borrowed_books() {
    int student_id, found = 0;

    printf("Enter student ID: ");
    scanf("%d", &student_id);
    for (int i = 0; i < student_count; i++) {
        if (students[i].student_id == student_id) {
            found = 1;
            if (students[i].borrowed_book_count > 0) {
                printf("Borrowed Books by Student %s:\n", students[i].name);
                for (int j = 0; j < students[i].borrowed_book_count; j++) {
                    printf("Book ID: %d, Title: %s\n", students[i].borrowed_books[j].book_id, students[i].borrowed_books[j].book_title);
                }
            } else {
                printf("No books borrowed by student %s.\n", students[i].name);
            }
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", student_id);
    }
}

void display_student_operations() {
    printf("Select a student operation:\n");
    printf("1. Add Student\n");
    printf("2. Update Student\n");
    printf("3. View Student\n");
    printf("4. Borrow Book\n");
}
