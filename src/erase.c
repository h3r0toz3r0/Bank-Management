/**
 * @name erase.c
 * @brief this function erases a customer account from the file system.
 * @retval ERASE_SUCCESS - success.
 * @retval ERASE_ERROR - error.
 */

// libraries
#include "erase.h"

int erase(void)
{
    printf("\n------------- ERASE ACCOUNT ------------\n");

    // declare variables
    int input;
    char str_input[SIZE_INPUT];
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
        return ERASE_ERROR;
    }

    // collect user information
    printf("Account Number: ");
    input = integer_input(input);
    if (input == INT_INPUT_ERROR)
    {
        free(cust_obj);
        destroy_customer(customer);
        return ERASE_ERROR;
    }

    // find customer and get cust_obj
    if (find_customer(input, cust_obj) == FIND_CUSTOMER_ERROR)
    {
        printf("Account number doesn't exist.\n");
        free(cust_obj);
        destroy_customer(customer);
        return ERASE_SUCCESS;
    }

    printf("\ncustomer: %s\n", cust_obj);

    // convert string to structure

    // print and verify structure to delete
    printf("\n\nAccount information:"
            "\n\tname:\t\t\t%s"
            "\n\taddress:\t\t%s %s, %s"
            "\n\tbirthday:\t\t%d/%d/%d"
            "\n\tcitizenship number:\t%d"
            "\n\tphone number:\t\t%s"
            "\n\taccount type:\t\t%d"
            "\nIs this the account you would like to delete (y/n)? ", 
            customer->name, customer->street, 
            customer->city, customer->state, 
            customer->birth_month, customer->birth_day, 
            customer->birth_year, customer->citizenship, 
            customer->phone, customer->type);
    if (string_input(str_input, SIZE_INPUT) == STR_INPUT_ERROR)
    {
        destroy_customer(customer);
        free(cust_obj);
        return ERASE_ERROR;
    }
    if(strcmp(str_input, "yes") == 0 || strcmp(str_input, "y") == 0 ||
        strcmp(str_input, "YES") == 0 || strcmp(str_input, "Y") == 0 ||
        strcmp(str_input,"Yes") == 0 )
    {
        // delete account
        printf("Account %d has been deleted.\n", customer->acc_num);
    }

    // free memory
    destroy_customer(customer);
    free(cust_obj);

    // return success
    printf("Returning to main menu.\n\n");
    return ERASE_SUCCESS;
}
