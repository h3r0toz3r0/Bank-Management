/**
 * @name main.c
 * @author Anna DeVries
 * @brief bank management program
 */

// libraries
#include "main.h"

int main(void)
{
    // declare local variables
    int select_bit;

    // initiate local variables
    select_bit = INIT_SELECTION_BIT;

    // for-loop till user chooses to exit
    while (select_bit != EXIT_SELECTION_BIT)
    {
        // prints welcome screen
        printf("\n\t--------------- CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM ---------------\n");
        printf("\n\tOPTIONS:\t%d - create a new account\n"
            "\t\t\t%d - update an existing account\n"
            "\t\t\t%d - remove existing account\n"
            "\t\t\t%d - deposit/withdraw from an account\n"
            "\t\t\t%d - view account information associated with account\n"
            "\t\t\t%d - exit\n\n", 
            CREATE_SELECTION_BIT, EDIT_SELECTION_BIT, ERASE_SELECTION_BIT,
            TRANSACT_SELECTION_BIT, VIEW_SELECTION_BIT, EXIT_SELECTION_BIT);

        // user input
        printf("Enter a number: ");
        select_bit = integer_input(select_bit);
        if(select_bit == INT_INPUT_ERROR)
        {
            printf("\ninteger_input() failed; unable to take user input.\n");
            return MAIN_ERROR;
        }

        // check select_bit for bank functionality
        // BankSystem runs regardless of error status for selection
        selection(select_bit);

        // zero out select_bit
        if (select_bit != EXIT_SELECTION_BIT)
        {
            select_bit = INIT_SELECTION_BIT;
        }
    }

    // exit message
    printf("\n\tTHANK YOU FOR USING THE BANK MANAGEMENT SYSTEM."
            "\n\tHAVE A GOOD DAY.\n\n");

    // return success
    return MAIN_SUCCESS;
}