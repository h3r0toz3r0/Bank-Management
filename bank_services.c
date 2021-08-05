//////////////////////////////////////////////////////////////
//              Bank Management Program                     //
//              Author: Anna DeVries                        //
//              Date: 3 August 2021                         //
//////////////////////////////////////////////////////////////

/*  includes     */
#include <stdio.h>
#include <stdlib.h>

/*  defines      */
#define DEBUG 1

void new_acc(void);
void view_list(void);
void edit(void);
void transact(void);
void erase(void);
void see(void);
void *welcome(char *user_input);

/*  new_acc() function:
    This function creates a new customer account. It asks 
    for some  personal and banking details of the customer 
    such as name, date of birth, citizenship number, 
    address and phone number. You can enter the amount to 
    deposit and choose one type of deposit account – saving, 
    current, fixed for 1 year, fixed for 2 years or fixed 
    for 3 years.
*/
void new_acc(void){
    return;
}

/*  view_list() function:
    With this function, you can view the customer’s banking 
    information such as account number, name, address and 
    phone number provided while creating the account.
*/
void view_list(void){
    return;
}

/*  edit() function:
    This function has been used for changing the address 
    and phone number of a particular customer account.
*/
void edit(void){
    return;
}

/*  transact() function:
    With this function, you can deposit and withdraw 
    money to and from a particular customer account.
*/
void transact(void){
    return;
}

/*  erase() function:
    This function is for deleting a customer account.
*/
void erase(void){
    return;
}

/*  see() function:
    This function shows account number, name, date of 
    birth, citizenship number, age, address, phone 
    number, type of account, amount deposited and date 
    of deposit. It also displays the amount of interest 
    corresponding to a particular account type.
*/
void see(void){
    return;
}

/*  welcome() function:
    This function displays and takes user input at main menu.
*/
void *welcome(char *user_input){
    printf("\t\t\tMAIN MENU\n\n");
    printf("1. Create new account\n");
    printf("2. Update information of existing account\n");
    printf("3. For transactions\n");
    printf("4. Check the details of existing account\n");
    printf("5. Removing existing account\n");
    printf("6. View cutomer's list\n");
    printf("7. Exit\n");

    // accepts user input
    printf("\nEnter your choice: ");
    *user_input = fgetc(stdin);
    printf("\n");

    // input sanitization 

    // perform desired function 

    // return user_input
    return user_input;
}

/*  main() function:
    This function displays the menu or welcome screen to 
    perform different banking activities mentioned below.
*/
int main(void){
    // local variables
    char *user_input;
    int user_input_size = 1;
    int check_bit = 0;

    // allocate memory
    user_input = malloc(user_input_size * sizeof(char*));

    // check memory; null if out of memory
    if ( user_input == NULL ){
        printf("\nmalloc failed; out of memory.\n");
        return -1;
    }

    // prints welcome screen
    printf("\n\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");

    // Call main menu page
    while ( check_bit == 0 ){
        user_input = welcome(user_input);

        // sanity check
        if ( DEBUG == 1 )
            printf("(debug only) user input: %c\n\n", *user_input);

        // check condition
        check_bit = 1;
    }

    // free memory
    free(user_input);

    // end program, return success
    return 0;
}