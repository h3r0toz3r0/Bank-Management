/**
 * @brief files.h - header file for files.c.
 */

// include guard
#ifndef FILES_H
#define FILES_H    

// libraries
#include <stdio.h>
#include "customer.h"
#include "helper.h"

// macros 
#define FILE_PATH                      "records.csv"
#define FIND_CUSTOMER_ERROR             NULL
#define INIT_FILE_ERROR                -1

#define WRITE_ERROR                    -1
#define WRITE_SUCCESS                   0
#define FPRINTF_ERROR                   0
#define FOPEN_ERROR                     NULL
#define END_FILE                       -1

// declare functions
char *find_customer(int accn);
int write_string(FILE *fp, char *string);
int write_int(FILE *fp, int num);
// int insert_file(struct Customer* customer);

#endif /* FILES_H */