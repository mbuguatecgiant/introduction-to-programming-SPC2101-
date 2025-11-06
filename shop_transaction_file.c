/*
Name:ANDLKARANJA 
REG NO:CT100/G/26193/25
DESCRIPTION: students_exam_results
*/
 #include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "sales.txt";
    double transaction, total = 0.0;
    int transaction_count = 0;
    
    
    file = fopen(filename, "r");
    
    
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        printf("Please make sure the file exists in the current directory.\n");
        return 1;
    }
    
    
    printf("Reading transactions from %s...\n\n", filename);
    
    while (fscanf(file, "%lf", &transaction) != EOF) {
        if (ferror(file)) {
            printf("Error reading from file.\n");
            fclose(file);
            return 1;
        }
        
        total += transaction;
        transaction_count++;
        printf("Transaction %d: $%.2f\n", transaction_count, transaction);
    }
    
    
    if (fclose(file) != 0) {
        printf("Error closing file.\n");
        return 1;
    }
    
    printf("File closed successfully.\n");
    
    
    printf("Summary:\n");
    printf("Number of transactions: %d\n", transaction_count);
    printf("Total sales for the day: $%.f\n", total);
    
    return 0;
}