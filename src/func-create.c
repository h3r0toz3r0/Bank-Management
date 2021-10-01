/*  
 * file: func_create.c
 * description: this function creates a new customer account. 
 * It asks for some  personal and banking details of the customer 
 * such as name, date of birth, citizenship number, 
 * address and phone number. You can enter the amount to 
 * deposit and choose one type of deposit account – saving, 
 * current, fixed for 1 year, fixed for 2 years or fixed 
 * for 3 years.
 * return: 0 for success, -1 for error
 */

//  includes
#include "func-create.h"
#include "struct-cust.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//  new_acc function
int func_create(void)
{
    // declare local variables
    struct Customer* customer;

    // initialize variables
    customer = NULL;
    customer = init_customer(customer);

    // collect user information
    printf("\n---------- CREATE NEW ACCOUNT ----------\n");
    printf("Enter New Account Owner Name: ");
    customer->name = user_input(customer->name, 50);
    printf("Enter Home Street Address: ");
    customer->street = user_input(customer->street, 100);
    printf("Enter Home City: ");
    customer->city = user_input(customer->city, 50);
    printf("Enter Home State: ");
    customer->state = user_input(customer->state, 20);
    printf("Enter Citizenship Number: ");
    customer->citizenship = user_input(customer->citizenship, 20);
    printf("Enter Birth Month (as number): ");
    customer->birth_month = user_input(customer->birth_month, 10);
    printf("Enter Birth Day: ");
    customer->birth_day = user_input(customer->birth_day, 2);
    printf("Enter Birth Year: ");
    customer->birth_year = user_input(customer->birth_year, 4);
    printf("Enter Phone Number: ");
    customer->phone = user_input(customer->phone, 20);
    printf("Enter New Account Type: ");
    customer->type = user_input(customer->type, 20);


    printf("%s\n", customer->name);

    // free memory
    free_customer(customer);

    return 0;
}

// int new_acc(void){
//     // local variables
//     Customer* guest;
//     int first_size = 32, last_size = 32, birth_size = 9, address_size = 64, citizen_size = 10, phone_size = 11, account_size = 2;
//     char* user_input;
//     int user_input_size = 4;
//     int c;


//     // print screen
//     printf("\t\t\tCREATE NEW ACCOUNT\n\n");

//     // accepts user input for account and clear stdin buffer
//     printf("First Name: ");
//     memmove(guest->first_name, get_input(guest->first_name, first_size), first_size);
//     printf("Last Name: ");
//     memmove(guest->last_name, get_input(guest->last_name, last_size), last_size);
//     printf("Birthday (yyyymmdd): ");
//     memmove(guest->birth, get_input(guest->birth, birth_size), birth_size);
//     printf("Citizenship Number: ");
//     memmove(guest->citizen_num, get_input(guest->citizen_num, citizen_size), citizen_size);
//     printf("Address: ");
//     memmove(guest->address, get_input(guest->address, address_size), address_size);
//     printf("Phone Number: ");
//     memmove(guest->phone, get_input(guest->phone, phone_size), phone_size);
//     printf("Account Type (1 = savings, 2 = current, 3 = fixed for 1 yr, 4 = fixed for 2 yr, 5 = fixed for 3 yr: ");
//     memmove(guest->account, get_input(guest->account, account_size), account_size);

//     printf("\n");

//     // Verify Information
//     while ( 1 ){
//         printf("Verify account info:\n");
//         printf("\t\tAccount Owner: \t\t%s %s\n", guest->first_name, guest->last_name);
//         printf("\t\tCitizenship Number: \t%s\n", guest->citizen_num);
//         printf("\t\tBirthday: \t\t%s\n", guest->birth);
//         printf("\t\tAddress: \t\t%s\n", guest->address);
//         printf("\t\tPhone Number: \t\t%s\n", guest->phone);
//         printf("\t\tAccount Type: \t\t%s\n", guest->account);
//         printf("is this correct? (yes/no) ");
//         strcmp(user_input, get_input(user_input, user_input_size));
//         printf("\n");

//         // check char* for y/yes
//         if ( strcmp(user_input, "yes") == 0 || strcmp(user_input, "y")  == 0 )
//             break;

//         // check char* for n/no
//         if ( strcmp(user_input, "no") == 0 || strcmp(user_input, "n") == 0){
//             // free memory
//             free(guest->first_name);
//             free(guest->last_name);
//             free(guest->birth); 
//             free(guest->address);
//             free(guest->citizen_num);
//             free(guest->phone); 
//             free(guest->account);
//             free(guest);
//             free(user_input);

//             // call new_acct
//             new_acc();
//         }

//         // sanity check
//         if ( DEBUG == 1 )
//             printf("(debug only) yes/no user input: %s\n", user_input);
//     }

//     // create a file and write data to the file
//     FILE *fptr = fopen("record.dat", "w");
//     if ( fptr == NULL ){
//         printf("Unable to create file.\n");
//         return -1;
//     }

//     // append to file
//     fputs(data, fptr);

//     // close file
//     fclose(fptr);


//     // return on success
//     return 0;
// }