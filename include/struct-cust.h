/*
 * name: struct-cust.h
 * description: header file for declaring the customer structure
 */

//  include guard
#ifndef CUSTOMER_H
#define CUSTOMER_H   

//  macros
#define NAME_LEN    50
#define STREET_LEN  100
#define CITY_LEN    50
#define STATE_LEN   20
#define CITZ_LEN    20
#define BM_LEN      11
#define BD_LEN      3
#define BY_LEN      5
#define PHONE_LEN   20
#define TYPE_LEN    20

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
char *user_input( char *string_input, int string_length );

#endif /* CUSTOMER_H */