/**
 * @name helper.c
 * @author Anna DeVries
 * @brief helper functions for the program.
 */

// libraries
#include "helper.h"

/**
 * @brief integer_input() gets user input for an integer.
 * @param integer_input - a declared and initialized integer variable.
 * @returns an integer from user input.
 * @retval integer_input - success.
 * @retval INT_INPUT_ERROR - error.
 */
int integer_input(int integer_input)
{
    // declare local variables
    int c;

    // user input
    if (scanf("%d", &integer_input) == EOF)
    {
        printf("\nscanf failed; input failure.\n");
        return INT_INPUT_ERROR;
    }

    // clears buffer of user input; getc has no errors defined
    while((c = getc(stdin)) != '\n' && c != EOF);

    // return integer input
    return integer_input;
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
    // define local variables
    int c;

    // collect user input
    if (fgets(string_input, string_length, stdin) == NULL) {
        printf("\nfgets failed; user input error.\n");
        return STR_INPUT_ERROR;
    }

    // clears stdin buffer; getc has no errors defined
    while((c = getc(stdin)) != '\n' && c != EOF);

    // removes erroneous newline character; strtok has no errors defined
    strtok(string_input, "\n");

    // return string input
    return string_input;
}

/**
 * @brief Selection() runs desired bank functionality. Options include: creating an account,
 * editing an account, erase an account, viewing account information, performing an account 
 * transaction, and exiting. Even a failure in the functions, the program will continue to run.
 * @param select_bit - interger received from user input to function selection.
 * @returns select_bit after executing desired function.
 * @retval select_bit - on success or error; errors are printed out only.
 */
int selection(int select_bit)
{
    if (select_bit == CREATE_SELECTION_BIT)
    {
        if (create() == CREATE_ERROR)
        {
            printf("\ncreate() failed; no account has been made.\n");
        }
    }
    else if (select_bit == EDIT_SELECTION_BIT)
    {
        if (edit() == EDIT_ERROR)
        {
            printf("\nedit() failed; no edits have been committed.\n");
        }
    }
    else if (select_bit == ERASE_SELECTION_BIT)
    {
        if (erase() == ERASE_ERROR)
        {
            printf("\nerase() failed; no account has been erased.\n");
        }
    }
    else if (select_bit == TRANSACT_SELECTION_BIT)
    {
        if (transact() == TRANSACT_ERROR)
        {
            printf("\ntransact() failed; no transactions have occured.\n");
        }
    }
    else if (select_bit == VIEW_SELECTION_BIT)
    {
        if (view() == VIEW_ERROR)
        {
            printf("\nview() failed; unable to find account information.\n");
        }
    }

    // return selection
    return select_bit;
}

////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief check_empty() check is char array is filled with zeros.
 * @returns success or error messages.
 * @retval CHECK_EMPTY_SUCCESS - success.
 * @retval CHECK_EMPTY_ERROR - error.
 */
int check_empty(char *string)
{
    if (string[0] != '\0')
    {
        return CHECK_EMPTY_ERROR;
    }

    return CHECK_EMPTY_SUCCESS;
}