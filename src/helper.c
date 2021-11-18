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
 * @brief integer_input() gets user input for an integer.
 * @returns an integer from user input.
 * @retval integer_input - success.
 * @retval INTEGER_INPUT_ERROR - error.
 */
int integer_input(void)
{
    // declare variables
    int character;
    int int_input;

    // user input
    if (scanf("%d", &int_input) == EOF)
    {
        perror("\nError reading user input");
        return INTEGER_INPUT_ERROR;
    }

    // clears buffer of user input; getc has no errors defined
    while((character = getc(stdin)) != '\n' && character != EOF);

    // return integer input
    return int_input;
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
 * @returns select_bit after executing desired function.
 * @retval select_bit - on success or error; errors are printed out only.
 */
int selection(int select_bit)
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
    return select_bit;
}

/**
 * @brief random_gen() mid-square method to generate a pseudorandom number.
 * @param randsize - integer specifying size of random number to create.
 * @returns a random number.
 * @retval seed - success.
 * @retval INTEGER_INPUT_ERROR - error.
 */
int random_gen(int randsize)
{
    // declare variables
    time_t current_time;
    int seed;
    int tmp_randsize;
    int tmp_half_randsize;

    // initialize variables
    time(&current_time); 
    seed = current_time;
    tmp_randsize = 1;
    tmp_half_randsize = 1;

    // logic to calculate size of random number
    for (int i = 0; i < randsize; i++)
    {
        tmp_randsize = tmp_randsize * 10;
    }
    for (int i = 0; i < (randsize / 2); i++)
    {
        tmp_half_randsize = tmp_half_randsize * 10;
    }

    // square current seed
    seed = seed * seed;

    // mid-square method
    seed = seed / tmp_half_randsize;
    seed = seed % tmp_randsize;

    // ensure positive
    seed = abs(seed);

    // check digit length
    if (seed < RANDOM_MIN || seed > RANDOM_MAX)
    {
        random_gen(randsize);
    }

    // return seed
    return seed;
}