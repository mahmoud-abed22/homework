
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    struct Student* next;
};

void printStudentWithLongestName(struct Student* head) {
    struct Student* current = head;
    struct Student* longestNameStudent = NULL;
    int longestNameLength = 0;
    
    while (current != NULL) {
        int currentNameLength = strlen(current->name);
        if (currentNameLength > longestNameLength) {
            longestNameLength = currentNameLength;
            longestNameStudent = current;
        }
        current = current->next;
    }
    
    if (longestNameStudent != NULL) {
        printf("The longest name in the list: %s\n", longestNameStudent->name);
        printf("Length: %d\n", longestNameLength);
    } else {
        printf("No records found.\n");
    }
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
    
    list = addStudentToList(list, "furkan", 101);
    list = addStudentToList(list, "ahmed", 102);
    list = addStudentToList(list, "muhammed", 103);
    list = addStudentToList(list, "ali", 104);
    list = addStudentToList(list, "Abdurrahmangazi", 105);

    printStudentWithLongestName(list);

    struct Student* current = list;
    while (current != NULL) {
        struct Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
