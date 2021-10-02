/*  
 * file: func_create.c
 * description: this function creates a new customer account. 
 * It asks for some  personal and banking details of the customer 
 * such as name, date of birth, citizenship number, 
 * address and phone number. You can enter the amount to 
 * deposit and choose one type of deposit account – saving, 
 * current, fixed for 1 year, fixed for 2 years or fixed 
 * for 3 years.
 * return: 0 for success, -1 for error
 */

//  includes
#include "func-create.h"
#include "struct-cust.h"
#include "func-files.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//  new_acc function
int func_create(void)
{
    printf("\n---------- CREATE NEW ACCOUNT ----------\n");

    // declare local variables
    struct Customer *customer;
    char *input;
    int check;
    int acc_num;

    // initialize variables
    check = 0;
    acc_num = 0;
    //memset(customer, 0, sizeof(struct Customer));
    customer = NULL;
    input = malloc(10 * sizeof(char));
    customer = init_customer(customer);

    // collect user information
    while ( check  == 0 )
    {
        printf("Enter New Account Owner Name: ");
        user_input(customer->name, STREET_LEN);
        printf("Enter Home Street Address: ");
        user_input(customer->street, STREET_LEN);
        printf("Enter Home City: ");
        user_input(customer->city, CITY_LEN);
        printf("Enter Home State: ");
        user_input(customer->state, STATE_LEN);
        printf("Enter Citizenship Number: ");
        user_input(customer->citizenship, CITZ_LEN);
        printf("Enter Birth Month (as number): ");
        user_input(customer->birth_month, BM_LEN);
        printf("Enter Birth Day: ");
        user_input(customer->birth_day, BD_LEN);
        printf("Enter Birth Year: ");
        user_input(customer->birth_year, BY_LEN);
        printf("Enter Phone Number: ");
        user_input(customer->phone, PHONE_LEN);
        printf("Enter New Account Type: ");
        user_input(customer->type, TYPE_LEN);

        // confirm information with user
        printf("\n\nAccount information:"
                "\n\tname:\t\t\t%s"
                "\n\taddress:\t\t%s %s, %s"
                "\n\tbirthday:\t\t%s/%s/%s"
                "\n\tcitizenship number:\t%s"
                "\n\tphone number:\t\t%s"
                "\n\taccount type:\t\t%s"
                "\nIs this correct? ", 
                customer->name, customer->street, 
                customer->city, customer->state, 
                customer->birth_month, customer->birth_day, 
                customer->birth_year, customer->citizenship, 
                customer->phone, customer->type);
        user_input(input, 10);
        if(strcmp(input, "yes") == 0 || strcmp(input, "y") == 0 ||
            strcmp(input, "YES") == 0 || strcmp(input, "Y") == 0 ||
            strcmp(input,"Yes") == 0 )
        {
            check = 1;
        }
    }
    printf("\n");

    // initilize account number
    acc_num = assign_acc();

    // append account number to structure
    customer->acc_num = acc_num;

    // add account to FILE
    insert_file(customer);

    // print confirmation
    printf("\nCongratulations - your new account has been registered.\n"
            "Your account number is %d.\n"
            "You will need this number to access your account.\n\n", acc_num);


    // free memory
    free_customer(customer);
    free(input);

    // return 0 for success
    return 0;
}