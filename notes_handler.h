#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

typedef struct {
    char **notes;
    int count;
    int capacity;
} NotesList;

void write_to_file(const char* text, NotesList* list);
void load_notes(NotesList* list);
void print_notes(const NotesList* list);
void clean_notes(NotesList* list);

#endif /** FILE_HANDLER_H */
