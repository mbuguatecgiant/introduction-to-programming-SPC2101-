/*
Name:ANDLKARANJA 
REG NO:CT100/G/26193/25
DESCRIPTION: students_exam_results
*/
#include <stdio.h>
#include <stdlib.h>


struct Student {
    char name[100];
    int registration_number;
    int total_marks;
};

int main() {
    FILE *file;
    struct Student student;
    
    
    file = fopen("results.dat", "rb");
    
    if (file == NULL) {
        printf("Error: Could not open file results.dat\n");
        return 1;
    }
    
    printf("Student Examination Results:\n");
    
    
    
    while (fread(&student, sizeof(struct Student), 1, file) == 1) {
    
        printf("Name: %s\n", student.name);
        printf("Marks: %d\n", student.total_marks);
        
    }
    
    fclose(file);
    return 0;
}