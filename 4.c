#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Dynamically create student list
Student* create_student_list(int n) {
    Student *studs = (Student*) malloc(n * sizeof(Student));

    if (studs == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    return studs;
}

// Add student details
void add_student(Student *studs, int i, char *name, int age, float gpa) {
    strcpy(studs[i].name, name);
    studs[i].age = age;
    studs[i].gpa = gpa;
}

// Display all student records
void display_students(Student *students, int size) {
    printf("\n--- Student Records ---\n");

    for (int i = 0; i < size; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n",
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

// Calculate average GPA
void calculate_average_gpa(Student *students, int size) {
    float sum = 0;

    for (int i = 0; i < size; i++) {
        sum += students[i].gpa;
    }

    printf("\nAverage GPA: %.2f\n", sum / size);
}

// Find student with highest GPA
void find_topper(Student *students, int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (students[i].gpa > students[highest].gpa) {
            highest = i;
        }
    }

    printf("\n--- Topper Details ---\n");
    printf("Name: %s\n", students[highest].name);
    printf("Age: %d\n", students[highest].age);
    printf("GPA: %.2f\n", students[highest].gpa);
}

// Free dynamically allocated memory
void free_student_list(Student *students) {
    free(students);
}

int main() {
    int number_of_students = 3;

    Student *student_list = create_student_list(number_of_students);

    add_student(student_list, 0, "Aladdin", 20, 3.5);
    add_student(student_list, 1, "Batman", 21, 3.7);
    add_student(student_list, 2, "Catwoman", 22, 3.8);

    display_students(student_list, number_of_students);

    calculate_average_gpa(student_list, number_of_students);

    find_topper(student_list, number_of_students);

    free_student_list(student_list);

    return 0;
}
