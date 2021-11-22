/**
 * @brief helper - header file for helper.c.
 */

// include guard
#ifndef HELPER_H
#define HELPER_H    

// macros 
#define CREATE_SELECTION    1
#define EDIT_SELECTION      2
#define ERASE_SELECTION     3
#define TRANSACT_SELECTION  4
#define VIEW_SELECTION      5
#define EXIT_SELECTION      6
#define ERROR_SELECTION     -1

#define STRING_INPUT_ERROR         NULL

#define RANDSIZE            6
#define RANDOM_MIN          111111
#define RANDOM_MAX          999999

// #define INIT_INTEGER            0
#define INIT_STRING             NULL
#define SIZE_INPUT              4

// declare functions
void find_string_length(char *str, int *length);
void **create_2D_array(int n_rows, int n_columns, int type_size);
void destroy_2D_array(void** array, int n_rows);
void **increase_rows_array(void **array, int n_rows, int add_rows, int n_cols, int type_size);

void selection(int select_bit);
void integer_input(int *int_input);
char *string_input(char *string_input, int string_length);
void random_gen(int *seed);

#endif /* HELPER_H */