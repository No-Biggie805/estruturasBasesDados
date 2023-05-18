#include "header.h"
int main()
{
    Classroom *graph = NULL;
    // Adding classrooms
    addClassroom(&graph, 101);
    addClassroom(&graph, 102);
    addClassroom(&graph, 103);

    // Adding students individually
    addStudent(&graph->students, 1, "John");
    addStudent(&graph->students, 2, "Alice");
    addStudent(&graph->students, 3, "Bob");

    // Linking students to classrooms
    addStudentToClassroom(graph, 101, graph->students);
    addStudentToClassroom(graph, 101, graph->students->next);
    addStudentToClassroom(graph, 102, graph->students->next->next);

    // Displaying students in classrooms
    displayStudentsInClassroom(graph, 101);
    displayStudentsInClassroom(graph, 102);

    // Freeing memory
    freeGraph(graph);

    return 0;
}