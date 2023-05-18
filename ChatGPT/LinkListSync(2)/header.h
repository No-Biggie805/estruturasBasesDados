#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for student linked list
typedef struct StudentNode
{
    int id;
    char name[50];
    struct StudentNode *next;
} Student;

// Node for classroom vertex in the graph
typedef struct ClassroomNode
{
    int roomNumber;
    Student *students;
    struct ClassroomNode *next;
} Classroom;

Student *createStudent(int id, const char *name);
void addStudent(Student **head, int id, const char *name);
Classroom *createClassroom(int roomNumber);
void addClassroom(Classroom **head, int roomNumber);
void addStudentToClassroom(Classroom *head, int roomNumber, Student *student);
void displayStudentsInClassroom(Classroom *head, int roomNumber);
void freeStudents(Student *head);
void freeGraph(Classroom *head);

