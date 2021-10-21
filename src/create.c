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
#include "create.h"

int create(void)
{
    printf("\n---------- CREATE NEW ACCOUNT ----------\n");

    // declare variables
    struct Customer *customer;
    char *input;
    // int check;

    // initialize variables
    check = INIT_CHECK;
    input = calloc(SIZE_INPUT, sizeof(char));
    customer = init_customer(customer);

    // check for errors
    if (customer == CUSTOMER_ERROR)
    {
        free(input);
        return CREATE_ERROR;
    }

    // collect user information
    while (check == INIT_CHECK)
    {
        customer = edit_customer(customer);
        if (customer == CUSTOMER_ERROR)
        {
            free(input);
            return CREATE_ERROR;
        }

        // ask for account type
        printf("Select Account Type\n"
                "\tEnter \"1\" for savings\n"
                "\tEnter \"2\" for checking: ");
        customer->type = integer_input(customer->type);
        if (customer->type == INT_INPUT_ERROR)
        {
            destroy_customer(customer);
            free(input);
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
                "\nIs this correct? ", 
                customer->name, customer->street, 
                customer->city, customer->state, 
                customer->birth_month, customer->birth_day, 
                customer->birth_year, customer->citizenship, 
                customer->phone, customer->type);
        if (string_input(input, SIZE_INPUT) == STR_INPUT_ERROR)
        {
            destroy_customer(customer);
            free(input);
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
    customer->acc_num = rand_number_generator(RANDSIZE);
    if (customer->acc_num == INT_INPUT_ERROR)
    {
        printf("\nrand_number_generator() failed; unable to assign unique account number.\n");
        destroy_customer(customer);
        free(input);
        return CREATE_ERROR;
    }

    ///////////////// check if accn number is unique

    // // add account to FILE
    // if (insert_file(customer) == INIT_FILE_ERROR)
    // {
    //     printf("\ninsert_file() failed; unable to save customer information.\n");
    //     destroy_customer(customer);
    //     free(input);
    //     return CREATE_ERROR;
    // }

    // print confirmation
    printf("\nCongratulations - your new account has been registered.\n"
            "Your account number is %d.\n"
            "You will need this number to access your account.\n\n", customer->acc_num);

    // free memory
    destroy_customer(customer);
    free(input);

    // return success
    return CREATE_SUCCESS;
}
