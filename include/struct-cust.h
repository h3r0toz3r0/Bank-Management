/*
 * name: struct-cust.h
 * description: header file for declaring the customer structure
 */

//  include guard
#ifndef CUSTOMER_H
#define CUSTOMER_H   

//  define structure
typedef struct Customer
{
    char *name;         //  account user name
    char *street;       //  user street address
    char *city;         //  user city
    char *state;        //  user state
    char *citizenship;  //  user citizenship number
    char *birth_month;  //  user birth month i.e. 1, 2, 3, etc
    char *birth_day;    //  user birth day
    char *birth_year;   //  user four digit birth year
    char *phone;        //  user phone number
    char *type;         //  account type    i.e.savings = 1
                        //                      current = 2
                        //                      fixed for 1 yr = 3
                        //                      fixed for 2 yr = 4
                        //                      fixed for 3 yr = 5
} customer;

//  declare function
struct Customer* init_customer(struct Customer* customer);
void free_customer(struct Customer* customer);

#endif /* CUSTOMER_H */