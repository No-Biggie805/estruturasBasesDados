#include "header.h"
int main()
{
    ClassroomNode *graph = NULL;

    // Adding classrooms
    addClassroom(&graph, 101);
    addClassroom(&graph, 102);
    addClassroom(&graph, 103);

    // Adding students to classrooms
    addStudentToClassroom(graph, 101, 1, "John");
    addStudentToClassroom(graph, 101, 2, "Emily");
    addStudentToClassroom(graph, 102, 3, "Michael");
    addStudentToClassroom(graph, 102, 4, "Sarah");
    addStudentToClassroom(graph, 103, 5, "David");

    // Displaying students in classrooms
    displayStudentsInClassroom(graph, 101);
    displayStudentsInClassroom(graph, 102);
    displayStudentsInClassroom(graph, 103);

    // Freeing memory
    freeGraph(graph);

    return 0;
}