/*
 * name: main.c
 * author: Anna DeVries
 * description: bank management program
 */

//  includes
#include <stdio.h>
#include "main.h"

//  selection function
int selection(int select_bit)
{
    // define local variables
    int tmp;

    // user input
    printf("Enter a number: ");
    scanf("%d", &select_bit);

    // sanitize input
    while ((tmp = getchar()) != EOF && tmp != '\n');

    // run desired function
    if (select_bit == 1)
    {
        func_create();
    }
    else if (select_bit == 2)
    {
        func_edit();
    }
    else if (select_bit == 3)
    {
        func_erase();
    }
    else if (select_bit == 4)
    {
        func_see();
    }
    else if (select_bit == 5)
    {
        func_transact();
    }
    else if (select_bit == 6)
    {
        func_view();
    }

    // return selection
    return select_bit;
}

//  main function
int main( void )
{
    // define local variables
    int select_bit;

    // initiate local variables
    select_bit = 0;

    // prints welcome screen
    printf("\n\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
    printf("\n\tOPTIONS:\t1 - create a new account\n"
           "\t\t\t2 - update an existing account\n"
           "\t\t\t3 - remove existing account\n"
           "\t\t\t4 - check details of an account\n"
           "\t\t\t5 - deposit/withdraw from an account\n"
           "\t\t\t6 - view customer information associated with account\n"
           "\t\t\t7 - exit\n\n");

    // for-loop till user chooses to exit
    while (select_bit != 7)
    {
        select_bit = selection(select_bit);
    }

    //  Exit at success
    return 0;
}