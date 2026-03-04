#include "inverted_search.h"

status_t create_database(hash_t *hash_table, file_t *file_head) {
    file_t* temp = file_head;
    while (temp) {
        FILE* file_ptr = fopen(temp->file_name, "r");
        if ( file_ptr == NULL ) {
            return FAILURE;  // File not accessible
        }

        char ch;
        char word[WORD_SIZE];
        int i = 0;

        // Read char by char, split on spaces and newlines
        while ( ( ch = getc(file_ptr) ) != EOF) {
            if ( ch == ' ' || ch == '\n' ) {
                if ( i > 0 ) {
                    word[i] = '\0';
                    i = 0;
                    insert_word(hash_table, word, temp->file_name);
                }
            } else {
                word[i++] = ch;
            }
        }

        // Insert last word if file doesn't end with whitespace
        if ( i > 0 ) {
            word[i] = '\0';
            insert_word(hash_table, word, temp->file_name);
        }

        fclose(file_ptr);
        temp = temp->next;  // Move to next file
    }
    return SUCCESS;
}
