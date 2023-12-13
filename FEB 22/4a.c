#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int rollNumber;
    char name[50];
    float cgpa;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *temp = NULL;

void insertNode(int rollNumber,  char *name, float cgpa) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->rollNumber = rollNumber;
    strcpy(newNode->name, name);
    newNode->cgpa = cgpa;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void searchStudent(int rollNumber) {
    temp = head;
    while (temp != NULL) {
        if (temp->rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("Name: %s\n", temp->name);
            printf("CGPA: %.2f\n", temp->cgpa);
            return;
        }
        temp = temp->next;
    }
    printf("Student with Roll Number %d not found.\n", rollNumber);
}
void displayList() {
    temp = head;
    printf("Student List:\n");
    while (temp != NULL) {
        printf("Roll Number: %d, Name: %s, CGPA: %.2f\n", temp->rollNumber, temp->name, temp->cgpa);
        temp = temp->next;
    }
}

int main() 
{
    int searchRollNumber;
    
    insertNode(1, "Vignesh", 9);
    insertNode(2, "Eswar", 9.5);
    insertNode(3, "Fakruddin", 9.8);
    insertNode(4, "Afzal", 9.2);
    insertNode(5, "Sumanth", 9.6);

    displayList();

    printf("\nEnter the Roll Number to search: ");
    scanf("%d", &searchRollNumber);
    searchStudent(searchRollNumber);
    return 0;
}
