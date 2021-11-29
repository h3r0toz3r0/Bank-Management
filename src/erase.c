/**
 * @file erase.c
 * @author Anna DeVries
 * @brief source contains all erase funcationality for program
 * @version 0.1
 * @date 2021-11-28
 * 
 * @copyright Copyright (c) 2021
 * 
 * @returns ERASE_SUCCESS on success, ERASE_FAILURE on error
 */

// libraries
#include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "erase.h"
// #include "files.h"
// #include "customer.h"
// #include "helper.h"

// erase functionality
int erase(void)
{
    printf("\n------------- ERASE ACCOUNT ------------\n");

    // // declare variables
    // int input;
    // char str_input[SIZE_INPUT];
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
    //     return ERASE_ERROR;
    // }

    // // collect user information
    // printf("Account Number: ");
    // input = integer_input(input);
    // if (input == INT_INPUT_ERROR)
    // {
    //     free(cust_obj);
    //     destroy_customer(customer);
    //     return ERASE_ERROR;
    // }

    // // find customer and get cust_obj
    // if (find_customer(input, cust_obj) == FIND_CUSTOMER_ERROR)
    // {
    //     printf("Account number doesn't exist.\n");
    //     free(cust_obj);
    //     destroy_customer(customer);
    //     return ERASE_SUCCESS;
    // }

    // // convert string to structure
    // customer = string_to_struct(customer, cust_obj);

    // // print and verify structure to delete
    // printf("\n\nAccount information:"
    //         "\n\taccount number:\t\t%d"
    //         "\n\tname:\t\t\t%s"
    //         "\n\taddress:\t\t%s %s, %s"
    //         "\n\tbirthday:\t\t%d/%d/%d"
    //         "\n\tcitizenship number:\t%d"
    //         "\n\tphone number:\t\t%s"
    //         "\n\taccount type:\t\t%d"
    //         "\nIs this the account you would like to delete (y/n)? ", 
    //         customer->acc_num, customer->name, customer->street, 
    //         customer->city, customer->state, 
    //         customer->birth_month, customer->birth_day, 
    //         customer->birth_year, customer->citizenship, 
    //         customer->phone, customer->type);
    // if (string_input(str_input, SIZE_INPUT) == STR_INPUT_ERROR)
    // {
    //     destroy_customer(customer);
    //     free(cust_obj);
    //     return ERASE_ERROR;
    // }
    // if(strcmp(str_input, "yes") == 0 || strcmp(str_input, "y") == 0 ||
    //     strcmp(str_input, "YES") == 0 || strcmp(str_input, "Y") == 0 ||
    //     strcmp(str_input,"Yes") == 0 )
    // {
    //     // delete account
    //     if (delete_line(customer->acc_num, FILE_PATH) == DELETE_LINE_ERROR)
    //     {
    //         printf("\ndelete_line() failed; unable to delete account.\n");
    //         destroy_customer(customer);
    //         free(cust_obj);
    //         return ERASE_ERROR;
    //     }
    //     printf("Account %d has been deleted.\n", customer->acc_num);
    // }

    // // free memory
    // destroy_customer(customer);
    // free(cust_obj);

    // // return success
    // printf("Returning to main menu.\n\n");
    return ERASE_SUCCESS;
}
