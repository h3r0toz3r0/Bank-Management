/**
 * @name view.c
 * @brief this function views and prints the customer information.
 * @retval VIEW_SUCCESS - success.
 * @retval VIEW_ERROR - error.
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "customer.h"
#include "helper.h"
#include "files.h"

int view(void)
{
    printf("\n------------- VIEW ACCOUNT -------------\n");

    // declare variables
    int input;
    struct Customer *customer;

    int length_customer_obj =   SIZE_NAME + SIZE_STREET + SIZE_CITY + 
                                SIZE_STATE + SIZE_PHONE + SIZE_SSN + 
                                SIZE_MONTH + SIZE_DAY + SIZE_YEAR + 
                                SIZE_TYPE;
    char *cust_obj = calloc(length_customer_obj, sizeof(char));

    // initialize variables
    input = INIT_INTEGER;
    customer = INIT_CUST;
    customer = init_customer(customer);

    // check for errors
    if (customer == CUSTOMER_ERROR)
    {
        free(cust_obj);
        return VIEW_ERROR;
    }

    // collect user information
    printf("Account Number: ");
    input = integer_input(input);
    if (input == INT_INPUT_ERROR)
    {
        free(cust_obj);
        destroy_customer(customer);
        return VIEW_ERROR;
    }

    // find customer and get cust_obj
    if (find_customer(input, cust_obj) == FIND_CUSTOMER_ERROR)
    {
        printf("Account number doesn't exist.\n");
        free(cust_obj);
        destroy_customer(customer);
        return VIEW_ERROR;
    }

    // convert string to structure
    customer = string_to_struct(customer, cust_obj);

    // print customer information
    if (customer->type == 2)
    {
        printf("\nAccount information:"
               "\n\taccount number:\t\t%d"
               "\n\tname:\t\t\t%s"
               "\n\taddress:\t\t%s %s, %s"
               "\n\tbirthday:\t\t%d/%d/%d"
               "\n\tcitizenship number:\t%d"
               "\n\tphone number:\t\t%s"
               "\n\taccount type:\t\tchecking\n\n", 
               customer->acc_num, customer->name, customer->street, 
               customer->city, customer->state, 
               customer->birth_month, customer->birth_day, 
               customer->birth_year, customer->citizenship, 
               customer->phone);
    }
    else if (customer->type == 1)
    {
        printf("\nAccount information:"
               "\n\taccount number:\t\t%d"
               "\n\tname:\t\t\t%s"
               "\n\taddress:\t\t%s %s, %s"
               "\n\tbirthday:\t\t%d/%d/%d"
               "\n\tcitizenship number:\t%d"
               "\n\tphone number:\t\t%s"
               "\n\taccount type:\t\tsavings\n\n", 
               customer->acc_num, customer->name, customer->street, 
               customer->city, customer->state, 
               customer->birth_month, customer->birth_day, 
               customer->birth_year, customer->citizenship, 
               customer->phone);
    }

    // free memory
    destroy_customer(customer);
    free(cust_obj);

    // return success
    printf("Returning to main menu.\n\n");
    return VIEW_SUCCESS;
}
