#include "inverted_search.h"

// Initialize each hash table slot with its index and empty list
void create_hash_table(hash_t *hash_table) {
    for ( int i = 0 ; i < HASH_SIZE ; i++ ) {
        hash_table[i].index = i;
        hash_table[i].head = NULL;
    }
}

int hash_function(const char *word) {
    if ( word == NULL ) {
        return 26;  // Default bucket for invalid input
    }
    char first_character = word[0];
    if ( first_character >= 'a' && first_character <= 'z' ) {
        return first_character - 'a' ;
    } else if ( first_character >= 'A' && first_character <= 'Z' ) {
        first_character = tolower(first_character);  // Normalize to lowercase
        return first_character - 'a' ;
    }
    return 26;  // Non-alphabetic characters go to bucket 26
}
