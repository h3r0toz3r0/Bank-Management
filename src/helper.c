/**
 * @name helper.c
 * @author Anna DeVries
 * @brief helper functions for the program.
 */

// libraries
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "helper.h"
// #include "create.h"
// #include "erase.h"
// #include "edit.h"
#include "tmp.h"

/**
 * @brief find_string_length() function finds length of null terminated string.
 * 
 * @param str string to find length of
 * @param length empty referenced variable
 */
void find_string_length(char *str, int *length)
{
    // declare variables
    char character;

    // initialize variables
    *length = 0;

    // calculate size of string (not using SIZEOF)
    for (character = *str; character != '\0'; character = *++str)
    {
        *length = *length + 1;
    }

    return;
}

/**
 * @brief create_2D_array() function creates a 2D void type array.
 * 
 * @param n_rows number of rows
 * @param n_columns number of columns
 * @param type_size type size of data entry i.e. sizeof(int), etc.
 * @returns 2D array of row x column
 */
void **create_2D_array(int n_rows, int n_columns, int type_size)
{
    // declare variables
    void **array;

    // allocate memory for array
    array = malloc(n_rows * sizeof(void *));

    // allocate memory for each row
    for (n_rows -= 1; n_rows >= 0; n_rows--)
    {
        array[n_rows] = calloc(n_columns, type_size);
    }

    // return array
    return array;
}

int **increase_rows_array(int **array, int n_rows, int add_rows, int n_cols)
{
    int **tmp = realloc( array, sizeof *array * (n_rows + add_rows) );
    if ( tmp )
    {
        array = tmp;
        for ( int i = 0; i < add_rows; i++ )
        {
            array[n_rows + i] = malloc( sizeof *array[n_rows + i] * n_cols);
        }
    }
    return array;
    // // use a single realloc for the char pointers to the first char of each row
    // // so we reallocate space for the pointers and then space for the actual rows.

    // // temporary array
    // int **pArray;

    // // allocate memory for array
    // array = malloc(n_rows * sizeof(void*));

    // // allocate memory for each row
    // for (n_rows -= 1; n_rows >= 0; n_rows--)
    // {
    //     array[n_rows] = calloc(n_columns, type_size);
    // }

    // pArray = (int **)realloc(array, n_rows * sizeof(*array));
    // memset(&pArray[n_rows - 1], 0, n_rows - (n_rows-1));
    
    // // 
    // pArray = realloc ( array, sizeof(int *) * n_rows + sizeof(int) * n_columns * n_rows);

    // if (pArray) {
    //     // calculate offset to the beginning of the actual data space
    //     int *pOffset = (int *)(pArray + n_rows);
    //     int   i;

    //     // fix up the pointers to the individual rows
    //     for (i = 0; i < n_rows; i++) {
    //         pArray[i] = pOffset;
    //         pOffset += n_columns;
    //     }
    // }

    // return pArray;
}

/**
 * @brief destroy_2D_array() function destroys 2D array.
 * 
 * @param n_rows number of rows
 * @param array 2D array
 */
void destroy_2D_array(void** array, int n_rows)
{
    // free memory for each row
    for (n_rows -= 1; n_rows >= 0; n_rows--)
        free(array[n_rows]);

    // free entire array
    free(array); 
}

/**
 * @brief integer_input() gets user input for an integer.
 * @param int_input - calls variable by reference.
 */
void integer_input(int *int_input)
{
    // declare variables
    int character;

    // user input
    if (scanf("%d", int_input) == EOF)
    {
        perror("\nError reading user input");
        return;
    }

    // clears buffer of user input; getc has no errors defined
    while((character = getc(stdin)) != '\n' && character != EOF);

    return;
}

/**
 * @brief string_input() function gets user input for a string.
 * @returns string from user input upon function return.
 * @param string_input - empty string_input value to fill. 
 * @param string_length - integer of length of string.
 * @retval string_input - success
 * @retval STR_INPUT_ERROR - error
 */
char *string_input(char *string_input, int string_length)
{
    // define variables
    int character;

    // collect user input
    if (fgets(string_input, string_length, stdin) == NULL) {
        perror("\nError reading user input");
        return STRING_INPUT_ERROR;
    }

    // clears stdin buffer; getc has no errors defined
    else if (strchr(string_input, '\n') == NULL) {
        while((character = getc(stdin)) != '\n' && character != EOF);
    }

    // removes erroneous newline character; strtok has no errors defined
    strtok(string_input, "\n");

    // return string input
    return string_input;
}

/**
 * @brief selection() runs desired bank functionality. Options include: creating an account,
 * editing an account, erase an account, viewing account information, performing an account 
 * transaction, and exiting. Even a failure in the functions, the program will continue to run.
 * @param select_bit - interger received from user input to function selection.
 * @returns void after performing desired bank function.
 */
void selection(int select_bit)
{
    switch(select_bit)
    {
        case CREATE_SELECTION :
            if (create() == CREATE_ERROR)
            {
                printf("\ncreate() failed; no account has been made.\n");
            }
        break;

        case EDIT_SELECTION :
            if (edit() == EDIT_ERROR)
            {
                printf("\nedit() failed; no edits have been saved.\n");
            }
        break;

        case ERASE_SELECTION :
            if (erase() == ERASE_ERROR)
            {
                printf("\nerase() failed; no account has been removed.\n");
            }
        break;

        case VIEW_SELECTION :
            if (view() == VIEW_ERROR)
            {
                printf("\nview() failed; unable to view the account.\n");
            }
        break;

        case TRANSACT_SELECTION :
            if (transact() == TRANSACT_ERROR)
            {
                printf("\ntransact() failed; unable to handle transactions.\n");
            }
        break;
    }

    // return selection
    return;
}

/**
 * @brief random_gen() mid-square method to generate a pseudorandom number.
 * @param randsize - integer specifying size of random number to create.
 * @returns a random number.
 * @retval seed - success.
 * @retval INTEGER_INPUT_ERROR - error.
 */
void random_gen(int *seed)
{
    // declare variables
    time_t current_time;
    int tmp_int[RANDSIZE];
    char tmp_char[RANDSIZE];
    char mid_string[RANDSIZE/2];
    char trim_string[RANDSIZE + 1];
    int mid_hash;
    int trim_hash;

    // obtain current time
    current_time = time(NULL);
    if (current_time == ((time_t) - 1))
    {
        perror("\nError in obtaining current time");
        return;
    }

    // trim current time to seed size
    for (int i = 0; i < RANDSIZE; i++)
    {
        tmp_int[i] = current_time % 10;
        current_time /= 10;
    }
    for (int i = 0; i < RANDSIZE; i++)
    {
        sprintf(&tmp_char[i], "%d", tmp_int[i]);
    }

    // convert the tmp_char[] into the int seed
    *seed = atoi(tmp_char);

    // square current seed
    *seed = (*seed) * (*seed);

    // initialize mid hashing number
    for (int i = 0; i <= (RANDSIZE/2); i++)
    {
        if (i == 0)
        {
            sprintf(&mid_string[i], "%d", 1);
        }
        else
        {
            sprintf(&mid_string[i], "%d", 0);
        }
    }
    mid_hash = atoi(mid_string);

    // initialize trim of mid hashing number
    for (int i = 0; i <= (RANDSIZE); i++)
    {
        if (i == 0)
        {
            sprintf(&trim_string[i], "%d", 1);
        }
        else
        {
            sprintf(&trim_string[i], "%d", 0);
        }
    }
    trim_hash = atoi(trim_string);

    // extract required digits
    *seed = *seed / mid_hash;
    *seed = *seed % trim_hash;

    // ensure positive
    *seed = abs(*seed);

    return;
}