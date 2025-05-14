#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
struct Student {
    int id;
    char name[50];
    float grade;
};
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count, int studentId);
void updateGrade(struct Student students[], int count, int studentId);
int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    do {
        printf("\n===== School Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Grade\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3: {
                int searchId;
                printf("Enter student ID to search: ");
                scanf("%d", &searchId);
                searchStudent(students, studentCount, searchId);
                break;
            }
            case 4: {
                int updateId;
                printf("Enter student ID to update grade: ");
                scanf("%d", &updateId);
                updateGrade(students, studentCount, updateId);
                break;
            }
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}
void addStudent(struct Student students[], int *count) {
    if (*count < MAX_STUDENTS) {
        struct Student newStudent;
        printf("Enter student ID: ");
        scanf("%d", &newStudent.id);
        for (int i = 0; i < *count; ++i) {
            if (students[i].id == newStudent.id) {
                printf("Student with the same ID already exists. Please choose a different ID.\n");
                return;
            }
        }
        printf("Enter student name: ");
        getchar();  
        scanf(" %[^\n]%*c", newStudent.name);  
        printf("Enter student grade: ");
        scanf("%f", &newStudent.grade);
        students[*count] = newStudent;
        (*count)++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached. Cannot add more students.\n");
    }
}
void displayStudents(struct Student students[], int count) {
    if (count > 0) {
        printf("\nStudent List:\n");
        printf("ID\tName\t\tGrade\n");
        for (int i = 0; i < count; ++i) {
            printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].grade);
        }
    } else {
        printf("No students to display.\n");
    }
}
void searchStudent(struct Student students[], int count, int studentId) {
    for (int i = 0; i < count; ++i) {
        if (students[i].id == studentId) {
            printf("Student found:\n");
            printf("ID\tName\t\tGrade\n");
            printf("%d\t%s\t\t%.2f\n", students[i].id, students[i].name, students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentId);
}
void updateGrade(struct Student students[], int count, int studentId) {
    for (int i = 0; i < count; ++i) {
        if (students[i].id == studentId) {
            printf("Enter new grade for %s: ", students[i].name);
            scanf("%f", &students[i].grade);
            printf("Grade updated successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentId);
}