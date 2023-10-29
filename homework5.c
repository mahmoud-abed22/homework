
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    struct Student* next;
};

struct Student* searchStudentByName(struct Student* head, const char* nameToFind) {
    struct Student* current = head;
    
    while (current != NULL) {
        if (strcmp(current->name, nameToFind) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL; 
}

struct Student* addStudentToList(struct Student* head, const char* name, int rollNumber) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    strcpy(newStudent->name, name);
    newStudent->rollNumber = rollNumber;
    newStudent->next = head;
    
    return newStudent;
}

int main() {
    struct Student* list = NULL;
    
    list = addStudentToList(list, "John", 101);
    list = addStudentToList(list, "Mary", 102);
    list = addStudentToList(list, "Michael", 103);
    list = addStudentToList(list, "Sarah", 104);

    printf("Enter a student name to search: ");
    char nameToSearch[50];
    scanf("%s", nameToSearch);

    struct Student* foundStudent = searchStudentByName(list, nameToSearch);

    if (foundStudent != NULL) {
        printf("Student found:\n");
        printf("Name: %s\n", foundStudent->name);
        printf("Roll Number: %d\n", foundStudent->rollNumber);
    } else {
        printf("Student not found.\n");
    }

    struct Student* current = list;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
