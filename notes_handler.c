#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "notes_handler.h"

#define BUFFER_SIZE 1024

void write_to_file(const char* text, NotesList* list) {
    if (list->count == list->capacity) {
        list->capacity *= 2;

        char** temp = realloc(list->notes, list->capacity * sizeof(char*));

        if (temp == NULL) {
            perror("realloc");

            return;
        }

        list->notes = temp;
    }

    list->notes[list->count] = malloc(strlen(text) + 1); // adding one because of the null-terminator
                                                         // example: "hello" in memory: [ h | e | l | l | o | \0 ] <- absence of null-terminator triggers SIGSEGV or UB
    strcpy(list->notes[list->count], text);
    list->count++;

    FILE* file = fopen("notes.txt", "a");

    if (file == NULL) {
        perror("fopen");

        return;
    }

    fwrite(text, sizeof(char), strlen(text), file);

    fclose(file);
}

void load_notes(NotesList* list) {
    FILE* file = fopen("notes.txt", "r");

    if (file == NULL) {
        return;
    }

    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        if (list->count == list->capacity) {
            list->capacity *= 2;

            char** temp = realloc(list->notes, list->capacity * sizeof(char*));

            if (temp == NULL) {
                perror("realloc");

                return;
            }

            list->notes = temp;
        }

        list->notes[list->count] = malloc(strlen(buffer) + 1);
        strcpy(list->notes[list->count], buffer);
        list->count++;
    }

    fclose(file);
}

void print_notes(const NotesList* list) {
    for (int i = 0; i < list->count; i++) {
        printf("[%d] %s\n", i, list->notes[i]);
    }
}

void clean_notes(NotesList* list) {
    for (int i = 0; i < list->count; i++) {
        free(list->notes[i]);
    }

    free(list->notes);
    list->count = 0;
    list->capacity = 2;
    list->notes = NULL;

    FILE* file = fopen("notes.txt", "w");

    if (file == NULL) {
        perror("fopen");

        return;
    }

    fclose(file);
}
