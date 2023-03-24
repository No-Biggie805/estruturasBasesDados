#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_NAME_LENGTH 100

typedef struct node {
    char code_name[MAX_CODE_NAME_LENGTH];
    int data;
    struct node *next;
} Node;

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("Code-name: %s, Data: %d\n", current->code_name, current->data);
        current = current->next;
    }
}

void add_to_list(Node **head_ptr, char *code_name, int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strncpy(new_node->code_name, code_name, MAX_CODE_NAME_LENGTH - 1);
    new_node->code_name[MAX_CODE_NAME_LENGTH - 1] = '\0';
    new_node->data = data;
    new_node->next = *head_ptr;
    *head_ptr = new_node;
}

void add_to_file(Node *head, char *filename) {
    FILE *fp;
    Node *current = head;

    fp = fopen(filename, "w");

    while (current != NULL) {
        fprintf(fp, "%s %d\n", current->code_name, current->data);
        current = current->next;
    }

    fclose(fp);
}

void view_from_file(Node **head_ptr, char *filename) {
    FILE *fp;
    char line[MAX_CODE_NAME_LENGTH + 5];
    char *code_name;
    int data;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    while (fgets(line, MAX_CODE_NAME_LENGTH + 5, fp) != NULL) {
        sscanf(line, "%s %d", code_name, &data);
        add_to_list(head_ptr, code_name, data);
    }

    fclose(fp);
}

void modify_node_data(Node *head, char *code_name, int new_data) {
    Node *current = head;

    while (current != NULL) {
        if (strcmp(current->code_name, code_name) == 0) {
            current->data = new_data;
            return;
        }
        current = current->next;
    }

    printf("Error: could not find node with code-name %s\n", code_name);
}

int main() {
    Node *head = NULL;

    add_to_list(&head, "code1", 10);
    add_to_list(&head, "code2", 20);
    add_to_list(&head, "code3", 30);
    add_to_list(&head, "code4", 40);

    printf("Initial linked list:\n");
    print_list(head);

    modify_node_data(head, "code2", 25);

    printf("Linked list after modifying node with code-name 'code2':\n");
    print_list(head);

    return 0;
}
