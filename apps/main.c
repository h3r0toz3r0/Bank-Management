//////////////////////////////////////////////////////////////
//              Bank Management Program                     //
//              Author: Anna DeVries                        //
//              Date: 3 August 2021                         //
//////////////////////////////////////////////////////////////

//  includes
#include "new-acc.h"
#include "edit.h"
#include "transact.h"
#include "see.h"
#include "erase.h"
#include "view-list.h"
#include <stdio.h>

//  main function
int main( void )
{
    // define local variables
    int selection;
    int tmp;

    // initiate local variables
    selection = 0;

    // prints welcome screen
    printf("\n\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n\tOPTIONS:\t1 - create a new account\n"
           "\t\t\t2 - update an existing account\n"
           "\t\t\t3 - deposit/withdraw from an account\n"
           "\t\t\t4 - check details of an account\n"
           "\t\t\t5 - remove existing account\n"
           "\t\t\t6 - view customer information associated with account\n"
           "\t\t\t7 - exit\n\n");

    // for-loop till user chooses to exit
    while (selection != 7)
    {
        // user input
        printf("Enter a number: ");
        scanf("%d", &selection);

        // sanitize input
        while ((tmp = getchar()) != EOF && tmp != '\n');

        // selection 1 = create
        if ( selection == 1 )
        {
            new_acc();
        }

        // selection 2 = update
        else if ( selection == 2 )
        {
            edit();
        }

        // selection 3 = transactions
        else if ( selection == 3 )
        {
            transact();
        }

        // selection 4 = check details
        else if ( selection == 4 )
        {
            see();
        }

        // selection 5 = remove
        else if ( selection == 5 )
        {
            erase();
        }

        // selection 6 = view list
        else if ( selection == 6 )
        {
            view_list();
        }
    }

    //  Exit at success
    return 0;
}