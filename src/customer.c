/**
 * @name customer.c
 * @brief this c program contains all customer struct functions.
 */

// include libraries
#include "customer.h"

/**
 * @brief init_customer() creates memory allocations for structure.
 * @param customer - a NULL customer structure.
 * @returns a initialized customer structure.
 * @retval customer - success
 * @retval CUSTOMER_ERROR - error
 */
struct Customer* init_customer(struct Customer* customer)
{
    // declare variables
    int i;

    // allocate memory
    customer = malloc(sizeof(struct Customer));

    // error checking
    if(customer == CUSTOMER_ERROR)
    {
        printf("\nmalloc failed; out of memory.\n");
        return CUSTOMER_ERROR;
    }

    // initialize variables 
    customer->acc_num       = INIT_VALUE;
    customer->citizenship   = INIT_VALUE;
    customer->birth_month   = INIT_VALUE;;
    customer->birth_day     = INIT_VALUE;
    customer->birth_year    = INIT_VALUE;
    customer->type          = INIT_VALUE;
    for (i = 0; i < SIZE_NAME; i++)
    {
        customer->name[i]   = INIT_VALUE_STR;
    }
    for (i = 0; i < SIZE_STREET; i++)
    {
        customer->street[i] = INIT_VALUE_STR;
    }
    for (i = 0; i < SIZE_CITY; i++)
    {
        customer->city[i]   = INIT_VALUE_STR;
    }
    for (i = 0; i < SIZE_STATE; i++)
    {
        customer->state[i]  = INIT_VALUE_STR;
    }
    for (i = 0; i < SIZE_PHONE; i++)
    {
        customer->phone[i]  = INIT_VALUE_STR;
    }

    // return customer
    return customer;
}

/**
 * @brief destroy_customer() cleanly frees memory allocations for structure.
 * @param customer - a customer structure.
 * @returns NULL.
 */
void destroy_customer(struct Customer* customer)
{
    // free memory
    free(customer);

    // return
    return;
}

/**
 * @brief edit_customer() adds user input into customer structure.
 * @returns customer structure with user updated values.
 * @retval customer - success
 * @retval CUSTOMER_ERROR - error
 */
struct Customer* edit_customer(struct Customer* customer)
{
    // collect user input
    printf("Enter Account Owner Name: ");
    if (string_input(customer->name, SIZE_NAME) == STR_INPUT_ERROR)
    {
        return CUSTOMER_ERROR;
    }

    printf("Enter Street Address: ");
    if (string_input(customer->street, SIZE_STREET) == STR_INPUT_ERROR)
    {
        return CUSTOMER_ERROR;
    }

    printf("Enter City: ");
    if (string_input(customer->city, SIZE_CITY) == STR_INPUT_ERROR)
    {
        return CUSTOMER_ERROR;
    }

    printf("Enter Two-Letter State Abbreviation: ");
    if (string_input(customer->state, SIZE_STATE) == STR_INPUT_ERROR)
    {
        return CUSTOMER_ERROR;
    }
   
    printf("Enter Citizenship Number: ");
    customer->citizenship = integer_input(customer->citizenship);
    if (customer->citizenship == INT_INPUT_ERROR)
    {
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }
    if (customer->citizenship > SSN_MAX || customer->citizenship < SSN_MIN)
    {
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    } 

    printf("Enter Birth Month As Digit (i.e. 1, 2, ..., 11, 12): ");
    customer->birth_month = integer_input(customer->birth_month );
    if (customer->birth_month == INT_INPUT_ERROR)
    {
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }
    if (MONTH_MIN > customer->birth_month || MONTH_MAX < customer->birth_month){
        printf("\nbirth month out of range; unable to create account.\n");
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }

    printf("Enter Birth Day: ");
    customer->birth_day = integer_input(customer->birth_day);
    if (customer->birth_day == INT_INPUT_ERROR)
    {
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }
    if (DAY_MIN > customer->birth_day || DAY_MAX < customer->birth_day){
        printf("\nbirth day out of range; unable to create account.\n");
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }

    printf("Enter Birth Year: ");
    customer->birth_year = integer_input(customer->birth_year);
    if (customer->birth_year == INT_INPUT_ERROR)
    {
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }
    if (YEAR_MAX < customer->birth_year || YEAR_MIN > customer->birth_year){
        printf("\nbirth year out of range; unable to create account.\n");
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }

    printf("Enter Phone Number: ");
    if (string_input(customer->phone, SIZE_PHONE) == STR_INPUT_ERROR)
    {
        destroy_customer(customer);
        return CUSTOMER_ERROR;
    }

    // NOTE - skipped account type to allow for portability of this function to other
    // bank functionalities.

    // return customer
    return customer;
}

// /**
//  * @brief find_customer() finds customer in database.
//  * @param accn - account number of customer.
//  * @param customer - customer structure.
//  * @returns customer structure with filled in parameters.
//  */
// struct Customer* find_customer(int accn, struct Customer* customer)
// {
//     printf("Account Number: %d\n", accn);

//     // define local variables
//     FILE *fp;
//     int len;
//     // int count;
//     // char local_customer[11];

//     // initialize local variables
//     len =   SIZE_NAME + SIZE_STREET + SIZE_CITY +
//             SIZE_STATE + SIZE_SSN + SIZE_MONTH +
//             SIZE_DAY + SIZE_YEAR + SIZE_PHONE + 
//             SIZE_TYPE + SIZE_ACCN;
//     char buffer[len];

//     // exit if file doesn't exist, no values to compare to
//     if(access(FILE_PATH, F_OK) != 0)
//     {
//         // return function
//         return CUSTOMER_ERROR;
//     }

//     // open file
//     fp = fopen(FILE_PATH, "r");
//     if (fp== NULL)
//     {
//         printf("\nfopen failed; retrying account number creation.\n");
//         return CUSTOMER_ERROR;
//     }

//     // read line by line
//     while (fgets(buffer, len - 1, fp))
//     {
//         // remove trailing newline
//         buffer[strcspn(buffer, "\n")] = 0;

//         // check buffer string to accn
//         if (atol(buffer) == accn)
//         {
//             // place values into customer
//             // count = 0;
//             char *tmp_ptr = strtok(buffer, DELIM);
//             while(tmp_ptr != NULL)
//             {
//                 printf("%s\n", tmp_ptr);
//                 tmp_ptr = strtok(NULL, DELIM);
//                 // strcpy(local_customer[count], tmp_ptr)
//                 // count++;
//             }
//         }
//     }

//     // close file
//     if (fclose(fp) == EOF)
//     {
//         printf("\nfclose failed; retrying account number creation.\n");
//         return CUSTOMER_ERROR;
//     }

//     // return function
//     return customer;
// }