/**
 * @name create.c
 * @brief this function creates a new customer account. 
 * It asks for some  personal and banking details of the customer 
 * such as name, date of birth, citizenship number, 
 * address and phone number. You can enter the amount to 
 * deposit and choose one type of deposit account – saving, 
 * current.
 * @retval CREATE_SUCCESS - success.
 * @retval CREATE_ERROR - error.
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"
#include "customer.h"
#include "helper.h"
#include "files.h"

int create(void)
{
    printf("\n---------- CREATE NEW ACCOUNT ----------\n");

    // declare variables
    struct Customer *customer;
    char input[SIZE_INPUT];
    int check;
    int length_customer_obj;

    // initialize variables
    check = INIT_INTEGER;
    customer = INIT_CUST;
    customer = init_customer(customer);
    length_customer_obj =   SIZE_NAME + SIZE_STREET + SIZE_CITY + 
                            SIZE_STATE + SIZE_PHONE + SIZE_SSN + 
                            SIZE_MONTH + SIZE_DAY + SIZE_YEAR + 
                            SIZE_TYPE;
    char cust_obj[length_customer_obj];

    // check for errors
    if (customer == CUSTOMER_ERROR)
    {
        return CREATE_ERROR;
    }

    // collect user information
    while (check == INIT_INTEGER)
    {
        customer = edit_customer(customer);
        if (customer == CUSTOMER_ERROR)
        {
            return CREATE_ERROR;
        }

        // ask for account type
        printf("Select Account Type\n"
                "\tEnter \"1\" for savings\n"
                "\tEnter \"2\" for checking: ");
        customer->type = integer_input(customer->type);
        if (customer->type == INT_INPUT_ERROR || 
            customer->type < TYPE_MIN || customer->type > TYPE_MAX)
        {
            destroy_customer(customer);
            return CREATE_ERROR;
        }

        // confirm information with user
        printf("\n\nAccount information:"
                "\n\tname:\t\t\t%s"
                "\n\taddress:\t\t%s %s, %s"
                "\n\tbirthday:\t\t%d/%d/%d"
                "\n\tcitizenship number:\t%d"
                "\n\tphone number:\t\t%s"
                "\n\taccount type:\t\t%d"
                "\nIs this correct (y/n)? ", 
                customer->name, customer->street, 
                customer->city, customer->state, 
                customer->birth_month, customer->birth_day, 
                customer->birth_year, customer->citizenship, 
                customer->phone, customer->type);
        if (string_input(input, SIZE_INPUT) == STR_INPUT_ERROR)
        {
            destroy_customer(customer);
            return CREATE_ERROR;
        }
        if(strcmp(input, "yes") == 0 || strcmp(input, "y") == 0 ||
            strcmp(input, "YES") == 0 || strcmp(input, "Y") == 0 ||
            strcmp(input,"Yes") == 0 )
        {
            check = EXIT_CHECK;
        }
    }

    // initilize account number
    customer->acc_num = random_gen(RANDSIZE);
    if (customer->acc_num == INT_INPUT_ERROR)
    {
        printf("\nrandom_gen() failed; unable to assign unique account number.\n");
        destroy_customer(customer);
        return CREATE_ERROR;
    }

    // check for unique account number
    if (find_customer(customer->acc_num, cust_obj) != FIND_CUSTOMER_ERROR)
    {
        printf("\nfind_customer() failed; account number is not unique, please try again.\n");
        destroy_customer(customer);
        return CREATE_ERROR;
    }

    // convert struct to string for csv storage
    if (struct_to_string(customer, cust_obj) == STR_INPUT_ERROR)
    {
        destroy_customer(customer);
        return CREATE_ERROR;
    }

    // insert customer string into file
    if (insert_file(cust_obj) == INIT_FILE_ERROR)
    {
        destroy_customer(customer);
        return CREATE_ERROR;
    }

    // print confirmation
    printf("\nCongratulations - your new account has been registered.\n"
            "Your account number is %d.\n"
            "You will need this number to access your account.\n\n", customer->acc_num);

    // free memory
    destroy_customer(customer);

    // return success
    return CREATE_SUCCESS;
}
