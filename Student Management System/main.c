#include <stdio.h>
#include <stdlib.h>

// Define the structure for a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};


void addStudent();
void viewStudents();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNumber);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n", s.rollNumber, s.name, s.marks);
    fclose(fp);
    printf("Student added successfully!\n");
}

void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("No records found (file does not exist yet).\n");
        return;
    }

    printf("\n--- Student List ---\n");
    printf("Roll\tName\tMarks\n");
    printf("---------------------------\n");
    while (fscanf(fp, "%d %s %f", &s.rollNumber, s.name, &s.marks) != EOF) {
        printf("%d\t%s\t%.2f\n", s.rollNumber, s.name, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    struct Student s;
    int searchRoll, found = 0;
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("No records available to search.\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &searchRoll);

    while (fscanf(fp, "%d %s %f", &s.rollNumber, s.name, &s.marks) != EOF) {
        if (s.rollNumber == searchRoll) {
            printf("\n--- Record Found ---\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\n", s.rollNumber, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", searchRoll);
    }
    fclose(fp);
}