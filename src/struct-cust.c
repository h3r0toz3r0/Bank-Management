/*  
 * file: struct-cust.c
 * description: these functions initialize and free the customer sturcture.
 */

//  includes
#include "struct-cust.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//  user_input() function asks user for string input for customer struct
char *user_input( char *string_input, int string_length )
{
    // allocate memory
    string_input = malloc(string_length * sizeof(char));

    // collect user input
    fgets(string_input, string_length, stdin);

    // return string input
    return string_input;
}

//  init_customer() function initializes memory for customer structure
struct Customer* init_customer(struct Customer* customer)
{
    // allocate memory
    customer = malloc(sizeof(struct Customer));
    customer->name = malloc(50 * sizeof(char));
    customer->street = malloc(100 * sizeof(char));
    customer->city = malloc(50 * sizeof(char));
    customer->state = malloc(20 * sizeof(char));
    customer->citizenship = malloc(20 * sizeof(char));
    customer->birth_month = malloc(10 * sizeof(char));
    customer->birth_day = malloc(2 * sizeof(char));
    customer->birth_year = malloc(4 * sizeof(char));
    customer->phone = malloc(20 * sizeof(char));
    customer->type = malloc(20 * sizeof(char));

    // error checking
    if( customer == NULL || customer->name == NULL ||
        customer->street == NULL || customer->city == NULL ||
        customer->state == NULL || customer->citizenship == NULL ||
        customer->birth_month == NULL || customer->birth_day == NULL ||
        customer->birth_year == NULL || customer->phone == NULL ||
        customer->type == NULL)
    {
        printf("\nmalloc failed; out of memory.\n");
        return NULL;
    }

    // return customer
    return customer;
}

//  free_customer() function frees all memory reserved for customer structure
void free_customer(struct Customer* customer)
{
    // free memory
    free(customer->name);
    free(customer->street);
    free(customer->city);
    free(customer->state);
    free(customer->citizenship);
    free(customer->birth_month);
    free(customer->birth_day);
    free(customer->birth_year);
    free(customer->phone);
    free(customer->type);
    free(customer);

    // return
    return;
}