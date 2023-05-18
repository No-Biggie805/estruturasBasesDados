#include "header.h"
// Function to add a new student to the student linked list
void addStudent(StudentNode **head, int studentID, const char *name)
{
    StudentNode *newStudent = (StudentNode *)malloc(sizeof(StudentNode));
    newStudent->studentID = studentID;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;

    if (*head == NULL)
        *head = newStudent;

    else
    {
        StudentNode *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = newStudent;
    }
}

// Function to add a new classroom vertex to the graph
void addClassroom(ClassroomNode **head, int roomNumber)
{
    ClassroomNode *newClassroom = (ClassroomNode *)malloc(sizeof(ClassroomNode));
    newClassroom->roomNumber = roomNumber;
    newClassroom->students = NULL;
    newClassroom->next = NULL;

    if (*head == NULL)//if list is still empty
        *head = newClassroom;//store students to of newClassrom node to linked list
    else
    {
        ClassroomNode *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = newClassroom;
    }
}

/*Importante!!??*/
// Function to add a student to a specific classroom vertex in the graph
void addStudentToClassroom(ClassroomNode *head, int roomNumber, int studentID, const char *name)
{
    ClassroomNode *current = head;//set current node pointer
    while (current != NULL)
    {
        if (current->roomNumber == roomNumber)//if the roomNumber inside the linked list is equal to local roomNumber
        {
            addStudent(&(current->students), studentID, name);//add student 'recursively' to classroom function
            return;
        }
        current = current->next;
    }
    printf("Classroom not found!\n");
}

/*Importante??!!*/
// Function to display all students in a specific classroom vertex in the graph
void displayStudentsInClassroom(ClassroomNode *head, int roomNumber)
{
    ClassroomNode *current = head;
    while (current != NULL)
    {
        if (current->roomNumber == roomNumber)
        {
            printf("Students in Classroom %d:\n", roomNumber);
            StudentNode *student = current->students;
            while (student != NULL)
            {
                printf("ID: %d, Name: %s\n", student->studentID, student->name);
                student = student->next;
            }
            return;
        }
        current = current->next;
    }
    printf("Classroom not found!\n");
}

// Function to free memory allocated for the student linked list
void freeStudents(StudentNode *head)
{
    StudentNode *current = head;
    while (current != NULL)
    {
        StudentNode *temp = current;
        current = current->next;
        free(temp);
    }
}

// Function to free memory allocated for the graph
void freeGraph(ClassroomNode *head)
{
    ClassroomNode *current = head;
    while (current != NULL)
    {
        ClassroomNode *temp = current;
        current = current->next;
        freeStudents(temp->students); // Free students in the classroom
        free(temp);
    }
}
