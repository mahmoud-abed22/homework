
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};

struct Student* addStudent(struct Student* head, int number, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    
    return newStudent;
}

void printStudentList(struct Student* head) {
    struct Student* current = head;
    int count = 0;
    
    while (current != NULL) {
        count++;
        printf("%d- %s %d %d\n", current->number, current->name, current->age, current->number + 200);
        current = current->next;
    }
    
    if (count == 0) {
        printf("No student records found.\n");
    }
}

int main() {
    struct Student* list = NULL;
    
    list = addStudent(list, 1, "Saliha", 27);
    list = addStudent(list, 2, "Ece", 19);
    
    printf("Student information on the screen:\n");
    printStudentList(list);

    struct Student* current = list;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
