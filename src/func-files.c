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
    fwrite(customer, sizeof(struct Customer),1, fd);

    // close file
    fclose(fd);

    // return
    return;
}