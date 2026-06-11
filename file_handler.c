#include <stdio.h>
#include <string.h>

#include "file_handler.h"

#define BUFFER_SIZE 1024

void write_to_file(const char* text) {
    FILE* file = fopen("notes.txt", "a");

    if (file == NULL) {
        perror("fopen");

        return;
    }

    fwrite(text, sizeof(char), strlen(text), file);

    fclose(file);

    printf("New note added!\n");
}

void read_from_file() {
    char string[BUFFER_SIZE];
    size_t bytes_to_read;

    FILE* file = fopen("notes.txt", "r");

    if (file == NULL) {
        perror("fopen");

        return;
    }

    while ((bytes_to_read = fread(string, sizeof(char), sizeof(string) - 1, file)) > 0) {
        string[bytes_to_read] = '\0';

        printf("%s", string);
    }

    fclose(file);
}
