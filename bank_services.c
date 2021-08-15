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
#define DEBUG 1

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
    char *citizen_num;          // customer citizenship number
    char *address;              // customer home address
    char *phone;                // customer phone number
    char *account;              // 1 = savings; 2 = current; 3 = fixed for 1 yr; 4 = fixed 
                                // for 2 yr; 5 = fixed for 3 yr
} Customer;

/*  user_input() function:
    inputs string to store user input and string size and outputs completed string.
    Takes user input and places it into string
*/
void *get_input(char *input_string, int input_size){
    // local variables
    int c;

    // accept user input
    if (fgets(input_string, input_size, stdin) == NULL) {
        printf("\nfgets failed; user input error.\n");
        return "0";
    }

    // clears stdin buffer if greater than char* allocation
    else if (strchr(input_string, '\n') == NULL) {
        while((c = getc(stdin)) != '\n' && c != EOF);
    }

    // removes erroneous newline character
    strtok(input_string, "\n");

    // return function
    return input_string;
}

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
    int first_size = 32, last_size = 32, birth_size = 9, address_size = 64, citizen_size = 10, phone_size = 11, account_size = 2;
    char* user_input;
    int user_input_size = 4;
    int c;

    // allocate memory
    guest = malloc(sizeof(Customer));
    guest->first_name = malloc(first_size * sizeof(char));
    guest->last_name = malloc(last_size * sizeof(char));
    guest->birth = malloc(birth_size * sizeof(char));
    guest->address = malloc(address_size * sizeof(char));
    guest->citizen_num = malloc(citizen_size * sizeof(char));
    guest->phone = malloc(phone_size * sizeof(char));
    guest->account = malloc(account_size * sizeof(char));
    user_input= malloc(user_input_size * sizeof(char));

    // error checking
    if ( guest->first_name == NULL || guest == NULL || user_input == NULL || guest->last_name == NULL || guest->birth == NULL || guest->address == NULL ){
        printf("\nmalloc failed; out of memory.\n");
        return -1;
    }

    // print screen
    printf("\t\t\tCREATE NEW ACCOUNT\n\n");

    // accepts user input for account and clear stdin buffer
    printf("First Name: ");
    memmove(guest->first_name, get_input(guest->first_name, first_size), first_size);
    printf("Last Name: ");
    memmove(guest->last_name, get_input(guest->last_name, last_size), last_size);
    printf("Birthday (yyyymmdd): ");
    memmove(guest->birth, get_input(guest->birth, birth_size), birth_size);
    printf("Citizenship Number: ");
    memmove(guest->citizen_num, get_input(guest->citizen_num, citizen_size), citizen_size);
    printf("Address: ");
    memmove(guest->address, get_input(guest->address, address_size), address_size);
    printf("Phone Number: ");
    memmove(guest->phone, get_input(guest->phone, phone_size), phone_size);
    printf("Account Type (1 = savings, 2 = current, 3 = fixed for 1 yr, 4 = fixed for 2 yr, 5 = fixed for 3 yr: ");
    memmove(guest->account, get_input(guest->account, account_size), account_size);

    printf("\n");

    // Verify Information
    while ( 1 ){
        printf("Verify account info:\n");
        printf("\t\tAccount Owner: \t\t%s %s\n", guest->first_name, guest->last_name);
        printf("\t\tCitizenship Number: \t%s\n", guest->citizen_num);
        printf("\t\tBirthday: \t\t%s\n", guest->birth);
        printf("\t\tAddress: \t\t%s\n", guest->address);
        printf("\t\tPhone Number: \t\t%s\n", guest->phone);
        printf("\t\tAccount Type: \t\t%s\n", guest->account);
        printf("is this correct? (yes/no) ");
        strcmp(user_input, get_input(user_input, user_input_size));
        printf("\n");

        // check char* for y/yes
        if ( strcmp(user_input, "yes") == 0 || strcmp(user_input, "y")  == 0 )
            break;

        // check char* for n/no
        if ( strcmp(user_input, "no") == 0 || strcmp(user_input, "n") == 0){
            // free memory
            free(guest->first_name);
            free(guest->last_name);
            free(guest->birth); 
            free(guest->address);
            free(guest->citizen_num);
            free(guest->phone); 
            free(guest->account);
            free(guest);
            free(user_input);

            // call new_acct
            new_acc();
        }

        // sanity check
        if ( DEBUG == 1 )
            printf("(debug only) yes/no user input: %s\n", user_input);
    }

    // create a file and write data to the file
    FILE *fptr = fopen("record.dat", "w");
    if ( fptr == NULL ){
        printf("Unable to create file.\n");
        return -1;
    }

    // append to file
    fputs(data, fptr);

    // close file
    fclose(fptr);


    // free memory
    free(guest->first_name);
    free(guest->last_name);
    free(guest->birth); 
    free(guest->address);
    free(guest->citizen_num);
    free(guest->phone); 
    free(guest->account);
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
