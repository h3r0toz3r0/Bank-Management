/*  
 * file: func-file.c
 * description: contains all functions for operating on files.
 */

//  includes
#include "func-files.h"
#include "struct-cust.h"
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <math.h> 
#include <stdlib.h>

//  assign_acc(): function that assigns a random, unused account number
void assign_acc(struct Customer* customer)
{
    // define local varibles
    int randsize;
    int seed;
    int count;
    int start_index;
    int len;
    time_t current_time;
    unsigned long tmp_seed;

    // initialize local variables
    randsize = ACC_LEN;
    count = 0;
    char buffer[randsize * 2 + 1];
    char final_buffer[randsize];

    // generate seed based on current time
    time(&current_time);
    seed = current_time;
    tmp_seed = seed * seed;

    // fill buffer with random numbers
    while( count < (2 * randsize) )
    {
        buffer[count++] = (tmp_seed % 10 + ('0' - 0));
        tmp_seed /= 10;
    }
    buffer[count] = '\0';

    // index buffer
    len = strlen(buffer);
    start_index = (len - randsize) / 2;
    strncpy(final_buffer, buffer + start_index, randsize - 1);
    final_buffer[randsize - 1] = '\0';

    // replace seed with random number
    seed = atol(final_buffer);

    // check FILE to ensure unique account number

    // add account number to customer struct
    strncpy(customer->acc_num, final_buffer, randsize);

    // return
    return;
}

//  insert_file(): function inserts new account into file
void insert_file(struct Customer* customer)
{
    // define local variables
    FILE *fd;

    // open file
    fd = fopen(FILE_PATH, "a");

    // append structure to file
    fwrite(customer->acc_num, sizeof(char), ACC_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->name, sizeof(char), NAME_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->street, sizeof(char), STREET_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->city, sizeof(char), CITY_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->state, sizeof(char), STATE_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->citizenship, sizeof(char), CITZ_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->birth_month, sizeof(char), BM_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->birth_day, sizeof(char), BD_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->birth_year, sizeof(char), BY_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->phone, sizeof(char), PHONE_LEN, fd);
    fwrite(",", sizeof(char), 1, fd);
    fwrite(customer->type, sizeof(char), TYPE_LEN, fd);
    fwrite("\n", sizeof(char), 1, fd);

    // close file
    fclose(fd);

    // return
    return;
}