/*  
 * file: new_acc.c
 * description: this function creates a new customer account. 
 * It asks for some  personal and banking details of the customer 
 * such as name, date of birth, citizenship number, 
 * address and phone number. You can enter the amount to 
 * deposit and choose one type of deposit account – saving, 
 * current, fixed for 1 year, fixed for 2 years or fixed 
 * for 3 years.
 */

//  includes
#include "new-acc.h"
#include <stdio.h>

//  new_acc function
int new_acc(void)
{
    printf("new-acc\n");

    return 0;
}

// int new_acc(void){
//     // local variables
//     Customer* guest;
//     int first_size = 32, last_size = 32, birth_size = 9, address_size = 64, citizen_size = 10, phone_size = 11, account_size = 2;
//     char* user_input;
//     int user_input_size = 4;
//     int c;

//     // allocate memory
//     guest = malloc(sizeof(Customer));
//     guest->first_name = malloc(first_size * sizeof(char));
//     guest->last_name = malloc(last_size * sizeof(char));
//     guest->birth = malloc(birth_size * sizeof(char));
//     guest->address = malloc(address_size * sizeof(char));
//     guest->citizen_num = malloc(citizen_size * sizeof(char));
//     guest->phone = malloc(phone_size * sizeof(char));
//     guest->account = malloc(account_size * sizeof(char));
//     user_input= malloc(user_input_size * sizeof(char));

//     // error checking
//     if ( guest->first_name == NULL || guest == NULL || user_input == NULL || guest->last_name == NULL || guest->birth == NULL || guest->address == NULL ){
//         printf("\nmalloc failed; out of memory.\n");
//         return -1;
//     }

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


//     // free memory
//     free(guest->first_name);
//     free(guest->last_name);
//     free(guest->birth); 
//     free(guest->address);
//     free(guest->citizen_num);
//     free(guest->phone); 
//     free(guest->account);
//     free(guest);
//     free(user_input);

//     // return on success
//     return 0;
// }