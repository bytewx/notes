#include <stdio.h>
#include <stdlib.h>

#include "notes_handler.h"

#define BUFFER_SIZE 1024

enum {
    CREATE_NOTE = '1',
    READ_NOTES = '2',
    CLEAN_NOTES = '3'
};

int main(void) {
    NotesList* list = malloc(sizeof(NotesList));

    load_notes(list);

    char input[BUFFER_SIZE];

    printf("Welcome to Notes!\n");

    while (true) {
        char choice[2];

        printf("Choose what you want to do: \n"
               "1) Add a note\n"
               "2) Read current notes\n"
               "3) Clean all notes\n\n"
               "Press any key to leave an application.\n\n"
               "Your choice: ");

        fgets(choice, sizeof(choice), stdin);

        int c;

        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (choice[0]) {
            case CREATE_NOTE:
                printf("Enter your note: ");

                fgets(input, BUFFER_SIZE, stdin);

                write_to_file(input, list);

                printf("New note added!\n");

                break;
            case READ_NOTES:
                printf("Your notes: \n\n");

                print_notes(list);

                break;
            case CLEAN_NOTES:
                clean_notes(list);

                printf("Notes cleaned.\n\n");

                break;
            default:
                printf("Invalid choice.\n\n");

                break;
        }
    }
}
