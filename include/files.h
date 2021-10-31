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
#define FILE_TMP_PATH                  "tmp.csv"
#define FIND_CUSTOMER_ERROR             NULL
#define ACCN_ITERATION                  1

#define INIT_FILE_ERROR                -1
#define INIT_FILE_SUCCESS               0

#define WRITE_ERROR                    -1
#define WRITE_SUCCESS                   0
#define FPRINTF_ERROR                   0
#define FOPEN_ERROR                     NULL
#define END_FILE                       -1

#define FILE_DNE                       -1
#define FILE_EXISTS                     0

#define DELETE_LINE_SUCCESS             0
#define DELETE_LINE_ERROR              -1

// declare functions
char *find_customer(int accn, char *line_cpy);
int write_string(FILE *fp, char *string);
int write_int(FILE *fp, int num);
int insert_file(char *cust_string);
int exists(char *filename);
int delete_line(int accn, char *filename);

#endif /* FILES_H */