/*  
 * file: func-file.c
 * description: contains all functions for operating on files.
 */

//  includes
#include "func-files.h"
#include "struct-cust.h"
#include <stdio.h>

//  assign_acc(): function that assigns a random, unused account number
int assign_acc(void)
{
    // return
    return 0;
}

//  insert_file(): function inserts new account into file
void insert_file(struct Customer* customer)
{
    // define local variables
    FILE *fd;

    // open file
    fd = fopen(FILE_PATH, "w");

    // append structure to file
    // fwrite("{", sizeof(char), 1, fd);
    fwrite(itoa(customer->acc_num), sizeof(int), 1, fd);
    fwrite(customer->name, sizeof(char), NAME_LEN, fd);
    fwrite(customer->street, sizeof(char), STREET_LEN, fd);
    fwrite(customer->city, sizeof(char), CITY_LEN, fd);
    fwrite(customer->state, sizeof(char), STATE_LEN, fd);
    fwrite(customer->citizenship, sizeof(char), CITZ_LEN, fd);
    fwrite(customer->birth_month, sizeof(char), BM_LEN, fd);
    fwrite(customer->birth_day, sizeof(char), BD_LEN, fd);
    fwrite(customer->birth_year, sizeof(char), BY_LEN, fd);
    fwrite(customer->phone, sizeof(char), PHONE_LEN, fd);
    fwrite(customer->type, sizeof(char), TYPE_LEN, fd);
    fwrite("}", sizeof(char), 1, fd);

    // close file
    fclose(fd);

    // return
    return;
}