//////////////////////////////////////////////////////////////
//              Bank Management Program                     //
//              Author: Anna DeVries                        //
//              Date: 3 August 2021                         //
//////////////////////////////////////////////////////////////

/*  includes     */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  defines      */
#define DEBUG 0

int new_acc(void);
void view_list(void);
void edit(void);
void transact(void);
void erase(void);
void see(void);
int welcome(int selection);
void determine_func(int selection);

/*  structs      */
typedef struct customer {
    char *last_name;            // customer last name
    char *first_name;           // customer first name
    char *birth;                // birthday as Dec 25, 1995 -> 19951225
    int citizen_num;            // customer citizenship number
    char *address;              // customer home address
    int phone;                  // customer phone number
    int account;                // 1 = savings, 2 = current, 
                                // 3 = fixed for 1 yr; 4 = fixed 
                                // for 2 yr; 5 = fixed for 3 yr
} Customer;

/*  new_acc() function:
    This function creates a new customer account. It asks 
    for some  personal and banking details of the customer 
    such as name, date of birth, citizenship number, 
    address and phone number. You can enter the amount to 
    deposit and choose one type of deposit account – saving, 
    current, fixed for 1 year, fixed for 2 years or fixed 
    for 3 years.
*/
int new_acc(void){
    // local variables
    Customer* guest;
    int first_size = 32;
    int last_size = 32;
    int bday_size = 9;
    int addr_size = 64;
    char *user_input;

    // allocate memory
    guest = malloc(sizeof(Customer));
    guest->first_name = malloc(first_size * sizeof(char));
    guest->last_name = malloc(last_size * sizeof(char));
    guest->birth = malloc(bday_size * sizeof(char));
    guest->address = malloc(addr_size * sizeof(char));
    user_input = malloc(sizeof(char) * 3);

    // error checking
    if ( guest->first_name == NULL || guest->last_name == NULL || guest->birth == NULL || guest->address == NULL || guest == NULL ){
        printf("\nmalloc failed; out of memory.\n");
        return -1;
    }

    // print screen
    printf("\t\t\tCREATE NEW ACCOUNT\n\n");

    // accepts user input for account and input sanitization  
    printf("\nAccount Owner Last Name: ");
    if ( fgets(guest->last_name, last_size, stdin) == NULL ){
        printf("\nfgets failed; user input error.\n");
        return -1;
    }
    if ( sscanf(guest->last_name, "%31[^\n]", guest->last_name) == EOF){
        printf("\nsscanf failed; user input error.\n");
        return -1;
    }
    printf("Account Owner First Name: ");
    if ( fgets(guest->first_name, first_size, stdin) == NULL ){
        printf("\nfgets failed; user input error.\n");
        return -1;
    }
    if ( sscanf(guest->first_name, "%31[^\n]", guest->first_name) == EOF){
        printf("\nsscanf failed; user input error.\n");
        return -1;
    }
    printf("Account Owner Birthday (yyyymmdd): ");
    if ( fgets(guest->birth, bday_size, stdin) == NULL ){
        printf("\nfgets failed; user input error.\n");
        return -1;
    }
    if ( sscanf(guest->birth, "%8[^\n]", guest->birth) == EOF){
        printf("\nsscanf failed; user input error.\n");
        return -1;
    }
    printf("Account Owner Physical Address: ");
    if ( fgets(guest->address, addr_size, stdin) == NULL ){
        printf("\nfgets failed; user input error.\n");
        return -1;
    }
    if ( sscanf(guest->address, "%63[^\n]", guest->address) == EOF){
        printf("\nsscanf failed; user input error.\n");
        return -1;
    }
    printf("\n");

    // Verify Information
    printf("Verify account info:\n");
    printf("\t\tAccount Owner: \t\t%s %s\n", guest->first_name, guest->last_name);
    printf("\t\tBirthday (yyyymmdd): \t%s\n", guest->birth);
    printf("\t\tAddress: \t\t%s\n", guest->address);
    printf("is this correct? (y/n) ");
    if ( fgets(user_input, 3, stdin) == NULL ){
        printf("\nfgets failed; user input error.\n");
        return -1;
    }
    if ( sscanf(user_input, "%s", user_input) == EOF){
        printf("\nsscanf failed; user input error.\n");
        return -1;
    }

    // Re-do create account if wrong
    if ( strcmp(user_input, "n") == 0 ||  strcmp(user_input, "no") == 0 ){
        new_acc();
    }

    // Continue if account correct
    else if ( strcmp(user_input, "y") == 0 ||  strcmp(user_input, "yes") == 0 ){
        printf("Account information saved.\nReturning to main menu.\n");
    }

    // free memory
    free(guest->first_name);
    free(guest->last_name);
    free(guest->birth);
    free(guest->address);
    free(guest);
    free(user_input);

    // return on success
    return 0;
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
int welcome(int selection){
    // local variables
    char *user_input;
    int user_input_size = 10;

    // allocate memory
    user_input = malloc(user_input_size * sizeof(char));

    // error checking
    if ( user_input == NULL ){
        printf("\nmalloc failed; out of memory.\n");
        return -1;
    }
    
    // print screen
    printf("\t\t\tMAIN MENU\n\n");
    printf("1. Create new account\n");
    printf("2. Update information of existing account\n");
    printf("3. For transactions\n");
    printf("4. Check the details of existing account\n");
    printf("5. Removing existing account\n");
    printf("6. View cutomer's list\n");
    printf("7. Exit\n");

    // accepts user input; pointer is now a single char from stdin
    printf("\nEnter your choice: ");
    if ( fgets(user_input, user_input_size, stdin) == NULL ){
        printf("\nfgets failed; user input error.\n");
        return -1;
    }
    printf("\n");

    // input sanitization 
    if ( sscanf(user_input, "%d", &selection) == EOF){
        printf("\nsscanf failed; user input error.\n");
        return -1;
    }

    // free memory
    free(user_input);

    // return user_input
    return selection;
}

/*  determine_func() function:
    This function determines which function selection calls and
    calls for that function.
*/
void determine_func(int selection){
    // selection 1 = create
    if ( selection == 1 )
        new_acc();

    // selection 2 = update
    else if ( selection == 2 )
        edit();

    // selection 3 = transactions
    else if ( selection == 3 )
        transact();

    // selection 4 = check details
    else if ( selection == 4 )
        see();

    // selection 5 = remove
    else if ( selection == 5 )
        erase();

    // selection 6 = view list
    else if ( selection == 6 )
        view_list();

    // return function
    return;
}

/*  main() function:
    This function displays the menu or welcome screen to 
    perform different banking activities mentioned below.
*/
int main(void){
    // local variables
    int selection = 0;

    // prints welcome screen
    printf("\n\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");

    // continuously calls main menu
    while ( selection != 7 ){
        // call main menu
        selection = welcome(selection);

        // sanity check
        if ( DEBUG == 1 )
            printf("(debug only) user input: %d\n\n", selection);

        // calls desired function
        determine_func(selection);
    }

    // end program, return success
    return 0;
}