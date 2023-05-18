
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for student linked list
typedef struct StudentNode
{
    int studentID;
    char name[50];
    struct StudentNode *next;
} StudentNode;

// Node for classroom vertex in the graph
typedef struct ClassroomNode
{
    int roomNumber;
    StudentNode *students;
    struct ClassroomNode *next;
} ClassroomNode;
void addStudent(StudentNode **head, int studentID, const char *name);
void addClassroom(ClassroomNode **head, int roomNumber);
void addStudentToClassroom(ClassroomNode *head, int roomNumber, int studentID, const char *name);
void displayStudentsInClassroom(ClassroomNode *head, int roomNumber);
void freeStudents(StudentNode *head);
void freeGraph(ClassroomNode *head);
