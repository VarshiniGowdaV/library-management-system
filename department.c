#include <stdio.h>
#include <string.h>
#include "department.h"

#define MAX_DEPARTMENTS 100
struct DEPARTMENT departments[MAX_DEPARTMENTS];
int department_count = 0;
void add_department()
{
    if (department_count >= MAX_DEPARTMENTS)
    {
        printf("Cannot add more departments. Maximum limit reached.\n");
        return;
    }

    struct DEPARTMENT new_department;
    printf("Enter department name: ");
    scanf(" %s", new_department.name);
    printf("Enter department ID: ");
    scanf("%d", &new_department.id);
    departments[department_count] = new_department;
    department_count++;

    printf("Department added successfully.\n");
}
void view_department()
{
    if (department_count == 0)
    {
        printf("No departments available.\n");
        return;
    }

    printf("\nList of Departments:\n");
    printf("--------------------\n");
    for (int i = 0; i < department_count; i++)
    {
        printf("Department %d:\n", i + 1);
        printf("  Name: %s\n", departments[i].name);
        printf("  ID: %d\n", departments[i].id);
        printf("--------------------\n");
    }
}

void display_department_operations() {
    printf("Select a department operation:\n");
    printf("1. Add Department\n");
    printf("2. View Department\n");
}
