/**
 * @brief files.h - header file for files.c.
 */

// include guard
#ifndef FILES_H
#define FILES_H    

// macros 
#define FILE_PATH           "records.csv"
#define FILE_HEADER         "accn,name,street,city,state,phone,ssn,birthmonth,birthday,birthyear,type,money\n"

#define INT_INIT             0
#define COLS_DELIMIN        ','
#define ROW_DELIMIN         '\n'

#define FILE_FAILURE        -1
#define FILE_SUCCESS         0

#define FPRINTF_ERROR        0
#define REMOVE_ERROR         0
#define POINTER_ERROR        NULL

// declare functions
int write_string_file(FILE *fp, char *string);
int create_file(char *filename, char *data);
int append_file(char *filename, char *data);
int insert_file(char *filename, char *data, int index);
int remove_line_file(char *filename, int index);
int find_line_file(char *filename, char *word);
char *pull_line_file(char *filename, int index);
int delete_file(char *filename);

// #define FILE_PATH                      "records.csv"
// #define FILE_TMP_PATH                  "tmp.csv"
// #define FIND_CUSTOMER_ERROR             NULL
// #define ACCN_ITERATION                  1

// #define INIT_FILE_ERROR                -1
// #define INIT_FILE_SUCCESS               0

// #define WRITE_ERROR                    -1
// #define WRITE_SUCCESS                   0
// #define FPRINTF_ERROR                   0
// #define FOPEN_ERROR                     NULL
// #define END_FILE                       -1

// #define FILE_DNE                       -1
// #define FILE_EXISTS                     0

// #define DELETE_LINE_SUCCESS             0
// #define DELETE_LINE_ERROR              -1

// #define REMOVE_SUCCESS                  0
// #define RENAME_SUCCESS                  0

// // declare functions
// char *find_customer(int accn, char *line_cpy);
// int write_string(FILE *fp, char *string);
// int write_int(FILE *fp, int num);
// int insert_file(char *cust_string);
// int exists(char *filename);
// int delete_line(int accn, char *filename);

#endif /* FILES_H */