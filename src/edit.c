/**
 * @file edit.c
 * @author Anna DeVries
 * @brief source contains all edit funcationality for program
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 * @returns EDIT_SUCCESS on success, EDIT_FAILURE on error
 */

// libraries
#include <stdio.h>
// #include <stdlib.h>
#include "edit.h"
// #include "customer.h"
// #include "helper.h"
// #include "files.h"

// edit functionality
int edit(void)
{
    printf("\n------------- EDIT ACCOUNT -------------\n");

    // // declare variables
    // int input;
    // struct Customer *customer;

    // int length_customer_obj =   SIZE_NAME + SIZE_STREET + SIZE_CITY + 
    //                             SIZE_STATE + SIZE_PHONE + SIZE_SSN + 
    //                             SIZE_MONTH + SIZE_DAY + SIZE_YEAR + 
    //                             SIZE_TYPE;
    // char *cust_obj = calloc(length_customer_obj, sizeof(char));

    // // initialize variables
    // input = INIT_INTEGER;
    // customer = INIT_CUST;
    // customer = init_customer(customer);

    // // check for errors
    // if (customer == CUSTOMER_ERROR)
    // {
    //     free(cust_obj);
    //     return EDIT_ERROR;
    // }

    // // collect user information
    // printf("Account Number: ");
    // input = integer_input(input);
    // if (input == INT_INPUT_ERROR)
    // {
    //     free(cust_obj);
    //     destroy_customer(customer);
    //     return EDIT_ERROR;
    // }

    // // find customer and get cust_obj
    // if (find_customer(input, cust_obj) == FIND_CUSTOMER_ERROR)
    // {
    //     printf("Account number doesn't exist.\n");
    //     free(cust_obj);
    //     destroy_customer(customer);
    //     return EDIT_ERROR;
    // }

    // // convert string to structure
    // customer = string_to_struct(customer, cust_obj);

    // // print options
    // printf("Welcome %s!\n\n", customer->name);
    // printf("Selection Options:\n");
    // printf("\t%d - update phone number\n", SELECTION_PHONE);
    // printf("\t%d - update address\n", SELECTION_ADDRESS);
    // printf("Selection: ");

    // // re-initialize variable
    // input = INIT_INTEGER;

    // // user input
    // input = integer_input(input);
    // if (input != SELECTION_PHONE || input != SELECTION_ADDRESS)
    // {
    //     printf("\nNo options selected.\n");
    //     printf("Returning to main menu.\n\n");
    //     destroy_customer(customer);
    //     free(cust_obj);
    //     return EDIT_ERROR;
    // }

    // // update customer struct for phone

    // // update customer struct for address

    // // convert struct to string

    // // delete old entry from records

    // // add new customer string to records

    // // free memory
    // destroy_customer(customer);
    // free(cust_obj);

    // // return success
    // printf("Returning to main menu.\n\n");
    return EDIT_SUCCESS;
}
