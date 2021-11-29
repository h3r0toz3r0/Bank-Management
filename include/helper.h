/**
 * @file helper.h
 * @author Anna DeVries
 * @brief header file for helper.c
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
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
#define ERROR_SELECTION    -1

#define RANDSIZE            6
#define STR_INPUT_FAILURE   NULL
#define STR_INIT            NULL
#define SIZE_INPUT          4

// declare functions
void find_string_length(char *str, int *length);
void **create_2D_array(int n_rows, int n_columns, int type_size);
void **increase_rows_array(void **array, int n_rows, int add_rows, int n_cols, int type_size);
void destroy_2D_array(void** array, int n_rows);
void integer_input(int *int_input);
char *string_input(char *string_input, int string_length);
void selection(int select_bit);
void random_gen(int *seed);

#endif /* HELPER_H */