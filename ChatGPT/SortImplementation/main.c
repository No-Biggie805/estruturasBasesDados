#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 30

// structure to represent a student
typedef struct Student
{
    char code_name[10];
    char first_name[20];
    char last_name[20];
    struct Student *next;
    int is_registered;
} Student;

// function to create a new student node
Student *create_student(char code_name[], char first_name[], char last_name[])
{
    Student *new_student = (Student *)malloc(sizeof(Student));
    strcpy(new_student->code_name, code_name);
    strcpy(new_student->first_name, first_name);
    strcpy(new_student->last_name, last_name);
    new_student->next = NULL;
    new_student->is_registered = 0;
    return new_student;
}

// function to add a student to the linked list
Student *add_student(Student *head, char code_name[], char first_name[], char last_name[])
{
    // create a new student node
    Student *new_student = create_student(code_name, first_name, last_name);
    if (head == NULL)
    {
        // if the linked list is empty, the new student becomes the head
        head = new_student;
    }
    else
    {
        // otherwise, add the new student to the end of the linked list
        Student *current_student = head;
        while (current_student->next != NULL)
        {
            current_student = current_student->next;
        }
        current_student->next = new_student;
    }
    return head;
}

// function to print the list of students
void print_students(Student *head)
{
    printf("List of students:\n");
    Student *current_student = head;
    while (current_student != NULL)
    {
        printf("%s - %s %s\n", current_student->code_name, current_student->first_name, current_student->last_name);
        current_student = current_student->next;
    }
}

// function to register a student in the linked list
void register_student(Student *head, char code_name[])
{
    Student *current_student = head;
    while (current_student != NULL)
    {
        if (strcmp(current_student->code_name, code_name) == 0)
        {
            current_student->is_registered = 1;
            printf("%s %s has been registered.\n", current_student->first_name, current_student->last_name);
            return;
        }
        current_student = current_student->next;
    }
    printf("Student with code name %s not found.\n", code_name);
}

// function to show a list of registered students
void show_registered_students(Student *head)
{
    printf("List of registered students:\n");
    Student *current_student = head;
    while (current_student != NULL)
    {
        if (current_student->is_registered)
        {
            printf("%s - %s %s\n", current_student->code_name, current_student->first_name, current_student->last_name);
        }
        current_student = current_student->next;
    }
}

// function to sort the list of students by code name
Student *sort_students_by_code_name(Student *head)
{
    int swapped;
    Student *current = head;
    Student *lptr = NULL;

    if (head == NULL)
        return head;

    do
    {
        swapped = 0;
        current = head;

        while (current->next != lptr)
        {
            if (strcmp(current->code_name, current->next->code_name) > 0)//if current is bigger than next 
            {
                // swap the nodes
                Student *temp = current->next;
                current->next = temp->next;
                temp->next = current;
                //-------------x---------------
                
                if (current == head)
                {
                    head = temp;
                }
                
                else
                {
                    Student *prev = head;
                    while (prev->next != current)
                    {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                current = temp;
                swapped = 1;
            }
            current = current->next;
        }
        lptr = current;
    } while (swapped);

    return head;
}

/*
void sortListByAge(Student *head)
{
    Student *current = head, *index = NULL;
    int tempCodeName;
    char tempName[MAX_NAME_LENGTH];

    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->code_name > index->code_name)
                {
                    tempCodeName = current->code_name;
                    current->code_name = index->code_name;
                    index->code_name = tempCodeName;

                    strncpy(tempName, current->code_name, MAX_NAME_LENGTH);
                    strncpy(current->code_name, index->code_name, MAX_NAME_LENGTH);
                    strncpy(index->code_name, tempName, MAX_NAME_LENGTH);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}
*/

// main function to test the linked list
int main()
{
    Student *head = NULL;
    head = add_student(head, "005", "John", "Doe");
    head = add_student(head, "010", "Jane", "Doe");
    head = add_student(head, "012", "Bob", "Smith");
    head = add_student(head, "003", "Alice", "Johnson");

    print_students(head);

    register_student(head, "001");
    register_student(head, "003");
    register_student(head, "005");

    show_registered_students(head);

    head = sort_students_by_code_name(head);
    print_students(head);

    return 0;
}
