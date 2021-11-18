/**
 * @brief helper - header file for helper.c.
 */

// include guard
#ifndef HELPER_H
#define HELPER_H    

// macros 
#define CREATE_SELECTION    1
#define EDIT_SELECTION     2
#define ERASE_SELECTION    3
#define TRANSACT_SELECTION  4
#define VIEW_SELECTION      5
#define EXIT_SELECTION      6

#define INTEGER_INPUT_ERROR    -1
#define STRING_INPUT_ERROR         NULL

#define RANDOM_MIN              111111
#define RANDOM_MAX              999999

#define INIT_INTEGER            0
#define INIT_STRING             NULL
#define SIZE_INPUT              4

// declare functions
void selection(int select_bit);
void integer_input(int *int_input);
char *string_input(char *string_input, int string_length);
int random_gen(int randsize);

#endif /* HELPER_H */