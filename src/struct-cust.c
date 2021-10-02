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
    // define local variables
    int c;

    // collect user input
    if (fgets(string_input, string_length, stdin) == NULL) {
        printf("\nfgets failed; user input error.\n");
        return "0";
    }

    // clears stdin buffer if greater than char* allocation
    else if (strchr(string_input, '\n') == NULL) {
        while((c = getc(stdin)) != '\n' && c != EOF);
    }

    // removes erroneous newline character
    strtok(string_input, "\n");

    // return string input
    return string_input;
}

//  init_customer() function initializes memory for customer structure
struct Customer* init_customer(struct Customer* customer)
{
    // allocate memory
    customer = malloc(sizeof(struct Customer));
    customer->name = malloc(NAME_LEN * sizeof(char));
    customer->street = malloc(STREET_LEN * sizeof(char));
    customer->city = malloc(CITY_LEN * sizeof(char));
    customer->state = malloc(STATE_LEN * sizeof(char));
    customer->citizenship = malloc(CITZ_LEN * sizeof(char));
    customer->birth_month = malloc(BM_LEN * sizeof(char));
    customer->birth_day = malloc(BD_LEN * sizeof(char));
    customer->birth_year = malloc(BY_LEN * sizeof(char));
    customer->phone = malloc(PHONE_LEN * sizeof(char));
    customer->type = malloc(TYPE_LEN * sizeof(char));
    customer->acc_num = malloc(ACC_LEN * sizeof(char));

    // initialize variables
    memset(customer->name, 0, NAME_LEN);
    memset(customer->street, 0, STREET_LEN);
    memset(customer->city, 0, CITY_LEN);
    memset(customer->state, 0, STATE_LEN);
    memset(customer->citizenship, 0, CITZ_LEN);
    memset(customer->birth_month, 0, BM_LEN);
    memset(customer->birth_day, 0, BD_LEN);
    memset(customer->birth_year, 0, BY_LEN);
    memset(customer->phone, 0, PHONE_LEN);
    memset(customer->type, 0, TYPE_LEN);
    memset(customer->acc_num, 0, ACC_LEN);

    // error checking
    if( customer == NULL || customer->name == NULL ||
        customer->street == NULL || customer->city == NULL ||
        customer->state == NULL || customer->citizenship == NULL ||
        customer->birth_month == NULL || customer->birth_day == NULL ||
        customer->birth_year == NULL || customer->phone == NULL ||
        customer->type == NULL || customer->acc_num == NULL)
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
    free(customer->acc_num);
    free(customer);

    // return
    return;
}