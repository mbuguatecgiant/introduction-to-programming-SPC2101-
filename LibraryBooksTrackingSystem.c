/*
Name:ANDLKARANJA 
REG NO:CT100/G/26193/25
DESCRIPTION: LIBRARY_BOOKS_TRACKING_SYSTEM
*/
#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char bookTitle[100];
    char choice;
    
    
    file = fopen("borrowed_books.txt", "a");
    
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    printf("LIBRARY BOOKS TRACKING SYSTEM");
    
    do {
        printf("\nEnter book title: ");
        fgets(bookTitle, sizeof(bookTitle), stdin);
        
        
        bookTitle[strcspn(bookTitle, "\n")] = 0;
        
        
        fprintf(file, "%s\n", bookTitle);
        
        
        printf("✓ Book title '%s' successfully stored in borrowed_books.txt\n", bookTitle);
        
        printf("\nDo you want to enter another book title? (y/n): ");
        scanf(" %c", &choice);
        getchar(); 
        
    } while (choice == 'y' || choice == 'Y');
    
    
    fclose(file);
    
    printf("\nThank you for using the Library Book Tracking System!\n");
    
    return 0;
}