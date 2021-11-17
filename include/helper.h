/**
 * @brief helper - header file for helper.c.
 */

// include guard
#ifndef HELPER_H
#define HELPER_H    

// macros 
#define CREATE_SELECTION_BIT    1
#define EDIT_SELECTION_BIT      2
#define ERASE_SELECTION_BIT     3
#define TRANSACT_SELECTION_BIT  4
#define VIEW_SELECTION_BIT      5
#define EXIT_SELECTION_BIT      6

#define INT_INPUT_ERROR        -1
#define STR_INPUT_ERROR         NULL
#define INIT_INTEGER            0
#define INIT_STRING             NULL
#define SIZE_INPUT              4

// declare functions
int selection(int select_bit);
int integer_input(int integer_input);
char *string_input(char *string_input, int string_length);
int random_gen(int randsize);

#endif /* HELPER_H */