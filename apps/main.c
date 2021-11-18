/**
 * @name main.c
 * @author Anna DeVries
 * @brief bank management program
 */

// libraries
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "helper.h"
#include "files.h"

int main(void)
{
    // declare variables
    int select_bit;

    // initiate variables
    select_bit = INIT_INTEGER;

    // initialize records file
    if (exists(FILE_PATH) == FILE_DNE)
    {
        // declare variables
        FILE *fp;

        // create file
        fp = fopen(FILE_PATH, "w");
        if (fp == NULL)
        {
            perror("\nError opening to file");
            exit(EXIT_FAILURE);
        }

        // close file
        fclose(fp);
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
        if(select_bit == INTEGER_INPUT_ERROR)
        {
            printf("\ninteger_input() failed; unable to take user input.\n");
            exit(EXIT_FAILURE);
        }

        // check select_bit for bank functionality
        // BankSystem runs regardless of error status for selection
        selection(select_bit);

        // zero out select_bit
        if (select_bit != EXIT_SELECTION)
        {
            select_bit = INIT_INTEGER;
        }
    }

    // exit message
    printf("\n\tTHANK YOU FOR USING THE BANK MANAGEMENT SYSTEM."
            "\n\tHAVE A GOOD DAY.\n\n");

    // exit gracefully
    exit(EXIT_SUCCESS);
}