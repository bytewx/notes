#include <stdio.h>

#include "file_handler.c"

#define BUFFER_SIZE 1024

enum {
    WRITE_TO_FILE = '1',
    READ_FROM_FILE = '2'
};

int main(void) {
    char input[BUFFER_SIZE];

    printf("Welcome to Notes!\n");

    while (true) {
        char choice[2];

        printf("Choose what you want to do: \n"
               "1) Add a note\n"
               "2) Read current notes\n\n"
               "Press any key to leave an application.\n\n"
               "Your choice: ");

        fgets(choice, sizeof(choice), stdin);

        int c;

        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice[0]) {
            case WRITE_TO_FILE:
                printf("Enter what you want to include in your file: ");

                fgets(input, BUFFER_SIZE, stdin);

                write_to_file(input);

                break;
            case READ_FROM_FILE:
                printf("Your notes: \n\n");

                read_from_file();

                break;
            default:
                printf("Invalid choice.\n");

                break;
        }
    }
}
