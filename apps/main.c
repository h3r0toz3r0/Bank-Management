/**
 * @file main.c
 * @author Anna DeVries
 * @brief source contains all main function for program
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "helper.h"
#include "files.h"

// main function
int main(void)
{
    // declare variables
    int select_bit;

    // initialize variables
    select_bit = ERROR_SELECTION;

    // initialize records file
    if (create_file(FILE_PATH, FILE_HEADER) == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }

    // for-loop till user chooses to exit
    while (select_bit != EXIT_SELECTION)
    {
        // prints welcome screen
        printf("\n\t--------------- CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM ---------------\n");
        printf("\n\tOPTIONS:\t%d - create a new account\n"
            "\t\t\t%d - update an existing account\n"
            "\t\t\t%d - remove existing account\n"
            "\t\t\t%d - deposit/withdraw from an account\n"
            "\t\t\t%d - view account information associated with account\n"
            "\t\t\t%d - exit\n\n", 
            CREATE_SELECTION, EDIT_SELECTION, ERASE_SELECTION,
            TRANSACT_SELECTION, VIEW_SELECTION, EXIT_SELECTION);

        // user input
        printf("Enter a number: ");
        integer_input(&select_bit);
        if(select_bit == ERROR_SELECTION)
        {
            printf("\nInteger_input() failed; unable to take user input.\n");
            exit(EXIT_FAILURE);
        }

        // check select_bit for bank functionality
        selection(select_bit);

        // zero out select_bit
        if (select_bit != EXIT_SELECTION)
        {
            select_bit = ERROR_SELECTION;
        }
    }

    // exit message
    printf("\n\tTHANK YOU FOR USING THE BANK MANAGEMENT SYSTEM."
            "\n\tHAVE A GOOD DAY.\n\n");

    // exit gracefully
    exit(EXIT_SUCCESS);
}