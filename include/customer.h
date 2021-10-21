/**
 * @brief customer.h - header file for customer.c.
 */

//  include guard
#ifndef CUSTOMER_H
#define CUSTOMER_H   

// libraries
#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

//  macros
#define CUSTOMER_ERROR  NULL

#define INIT_VALUE      0
#define INIT_VALUE_STR '\0'

#define SIZE_NAME       50
#define SIZE_STREET     100
#define SIZE_CITY       50
#define SIZE_STATE      3
#define SIZE_PHONE      16

#define SSN_MAX         999999999
#define SSN_MIN         111111111
#define MONTH_MAX       12
#define MONTH_MIN       1
#define DAY_MAX         31
#define DAY_MIN         1
#define YEAR_MAX        2021
#define YEAR_MIN        1920

#define DELIM           ","

//  define structure
typedef struct Customer
{
    int acc_num;                //  account number
    char name[SIZE_NAME];       //  account user name
    char street[SIZE_STREET];   //  user street address
    char city[SIZE_CITY];       //  user city
    char state[SIZE_STATE];     //  user state
    int citizenship;            //  user citizenship number
    int birth_month;            //  user birth month i.e. 1, 2, 3, etc
    int birth_day;              //  user birth day
    int birth_year;             //  user four digit birth year
    char phone[SIZE_PHONE];     //  user phone number
    int type;                   //  account type    i.e.savings     = 1
                                //                      checking    = 2
} customer;

//  declare function
struct Customer* init_customer(struct Customer* customer);
void destroy_customer(struct Customer* customer);
struct Customer* edit_customer(struct Customer* customer);
// struct Customer* find_customer(int accn, struct Customer* customer);

#endif /* CUSTOMER_H */