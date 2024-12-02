#include <stdio.h>
#include <string.h>

struct staff
{
    char name[50];
    int id;
    char dept[50];
};
#define MAX_STAFF 100

struct staff staff_members[MAX_STAFF];
int staff_count = 0;
void add_staff()
{
    if (staff_count >= MAX_STAFF)
    {
        printf("Staff database is full.\n");
        return;
    }

    struct staff new_staff;

    printf("Enter staff_name: ");
    scanf(" %s", new_staff.name);
    printf("Enter staff_ID: ");
    scanf("%d", &new_staff.id);
    printf("Enter staff_department: ");
    scanf(" %s", new_staff.dept);

    staff_members[staff_count++] = new_staff;
    printf("Staff added successfully.\n");
}

void remove_staff()
{
    int id_to_remove;
    printf("Enter the ID of the staff member to remove: ");
    scanf("%d", &id_to_remove);
    for (int i = 0; i < staff_count; i++)
    {
        if (staff_members[i].id == id_to_remove)
        {
            for (int j = i; j < staff_count - 1; j++)
            {
                staff_members[j] = staff_members[j + 1];
            }
            staff_count--;
            printf("Staff member removed successfully.\n");
            return;
        }
    }

    printf("Staff member with ID %d not found.\n", id_to_remove);
}

void view_staff()
{
    if (staff_count == 0)
    {
        printf("No staff members in the database.\n");
        return;
    }

    printf("List of Staff Members:\n");
    for (int i = 0; i < staff_count; i++)
    {
        printf("Staff %d:\n", i + 1);
        printf("staff_Name: %s\n", staff_members[i].name);
        printf("staff_ID: %d\n", staff_members[i].id);
        printf("staff_Department: %s\n\n", staff_members[i].dept);
    }
}
void staff_borrow_book()
{
    int id;
    printf("Enter the ID of the staff borrowing the book: ");
    scanf("%d", &id);
    printf("Staff borrowing functionality is not implemented yet.\n");
}
void view_staff_borrowed_books()
{
    printf("Viewing borrowed books by staff is not implemented yet.\n");
}
void display_staff_operations() {
    printf("Select a staff operation:\n");
    printf("1. Add Staff\n");
    printf("2. Remove Staff\n");
    printf("3. View Staff\n");
}

