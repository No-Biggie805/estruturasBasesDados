#include "header.h"
Student *createStudent(int id, const char *name)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->id = id;
    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->next = NULL;
    return newStudent;
}

void addStudent(Student **head, int id, const char *name)
{
    Student *newStudent = createStudent(id, name);
    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        Student *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newStudent;
    }
}

Classroom *createClassroom(int roomNumber)
{
    Classroom *newClassroom = (Classroom *)malloc(sizeof(Classroom));
    newClassroom->roomNumber = roomNumber;
    newClassroom->next = NULL;
    newClassroom->students = NULL;
    return newClassroom;
}

void addClassroom(Classroom **head, int roomNumber)
{
    Classroom *newClassroom = createClassroom(roomNumber);
    if (*head == NULL)
    {
        *head = newClassroom;
    }
    else
    {
        Classroom *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newClassroom;
    }
}

void addStudentToClassroom(Classroom *head, int roomNumber, Student *student)
{
    Classroom *current = head;
    while (current != NULL)
    {
        if (current->roomNumber == roomNumber)
        {
            if (current->students == NULL)
                current->students = student;

            else
            {
                Student *currentStudent = current->students;
                while (currentStudent->next != NULL)
                    currentStudent = currentStudent->next;
                currentStudent->next = student;
            }
            return;
        }
        current = current->next;
    }
    printf("Classroom %d not found!\n", roomNumber);
}

void displayStudentsInClassroom(Classroom *head, int roomNumber)
{
    Classroom *current = head;
    while (current != NULL)
    {
        if (current->roomNumber == roomNumber)
        {
            printf("Students in Classroom %d:\n", roomNumber);
            Student *student = current->students;
            while (student != NULL)
            {
                printf("ID: %d, Name: %s\n", student->id, student->name);
                student = student->next;
            }
            return;
        }
        current = current->next;
    }
    printf("Classroom %d not found!\n", roomNumber);
}

void freeStudents(Student *head)
{
    Student *current = head;
    while (current != NULL)
    {
        Student *temp = current;
        current = current->next;
        free(temp);
    }
}

void freeGraph(Classroom *head)
{
    Classroom *current = head;
    while (current != NULL)
    {
        Classroom *temp = current;
        current = current->next;
        freeStudents(temp->students);
        free(temp);
    }
}