#ifndef STAFF_H
#define STAFF_H
#define MAX_STAFF 15
#define STAFF_LIST 15
struct staff {
    char name[50];
    int id;
    char dept[50];
    char position[50];
};
void add_staff();
void remove_staff();
void view_staff();
void staff_borrow_book();
void view_staff_borrowed_books();

#endif // STAFF_H
