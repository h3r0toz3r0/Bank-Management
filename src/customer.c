/**
 * @name customer.c
 * @brief this c program contains all customer struct functions.
 */

// include libraries
#include "customer.h"

/**
 * @brief struct_to_string() takes a customer structure and converts it to a string.
 * @returns a string containing the customer object.
 * @retval cust_obj - success.
 * @retval STR_INPUT_ERROR - error.
 */
char *struct_to_string(struct Customer* customer, char *cust_obj)
{
    // declare variables
    int length_customer_obj;

    // initialize variables
    length_customer_obj =       SIZE_NAME + SIZE_STREET + SIZE_CITY + 
                                SIZE_STATE + SIZE_PHONE + SIZE_SSN + 
                                SIZE_MONTH + SIZE_DAY + SIZE_YEAR + 
                                SIZE_TYPE;

    // ensure customer obj is cleared
    memset(cust_obj, INIT_INTEGER, length_customer_obj);

    // convert structure to string
    if (snprintf(cust_obj, length_customer_obj, "%d,%s,%s,%s,%s,%d,"
                "%d,%d,%d,%s,%d\n", 
                customer->acc_num, customer->name, 
                customer->street, customer->city, customer->state, 
                customer->citizenship, customer->birth_month, 
                customer->birth_day, customer->birth_year, 
                customer->phone, customer->type) < INIT_CHECK)
    {
        printf("\nsnprintf error; unable to convert struct to string.\n");
        return STR_INPUT_ERROR;
    }

    // return success
    return cust_obj;
}

/**
 * @brief string_to_struct() takes a customer object string and converts it to the customer struct.
 * @returns a customer structure.
 * @retval customer - success.
 */
struct Customer* string_to_struct(struct Customer* customer, char *cust_obj)
{
    // declare variables
    char *ptr;
    int count;

    // initiate variables 
    count = 0;
    
    // break apart line by commas
    ptr = strtok(cust_obj,",");
    while (ptr != NULL)
    {
        // convert string to struct
        if (0 == count)
        {
            customer->acc_num = atoi(ptr);
        }
        else if (count == 1)
        {
            strcpy(customer->name, ptr);
        }
        else if (count == 2)
        {
            strcpy(customer->street, ptr);
        }
        else if (count == 3)
        {
            strcpy(customer->city, ptr);
        }
        else if (count == 4)
        {
            strcpy(customer->state, ptr);
        }
        else if (count == 5)
        {
            customer->citizenship = atoi(ptr);
        }
        else if (count == 6)
        {
            customer->birth_month = atoi(ptr);
        }
        else if (count == 7)
        {
            customer->birth_day = atoi(ptr);
        }
        else if (count == 8)
        {
            customer->birth_year = atoi(ptr);
        }
        else if (count == 9)
        {
            strcpy(customer->phone, ptr);
        }
        else if (count == 10)
        {
            customer->type = atoi(ptr);
        }

        // increment count and ptr
        ptr = strtok(NULL, ",");
        count++;
    }

    // return success
    return customer;
}

/**
 * @brief init_customer() creates memory allocations for structure.
 * @param customer - a NULL customer structure.
 * @returns a initialized customer structure.
 * @retval customer - success.
 * @retval CUSTOMER_ERROR - error.
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
 * @retval customer - success.
 * @retval CUSTOMER_ERROR - error.
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