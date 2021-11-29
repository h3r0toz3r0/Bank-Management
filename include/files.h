/**
 * @file files.h
 * @author Anna DeVries
 * @brief header file for files.c
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// include guard
#ifndef FILES_H
#define FILES_H    

// macros 
#define FILE_PATH           "records.csv"
#define FILE_HEADER         "accn,name,street,city,state,phone,ssn,birthmonth,birthday,birthyear,type,money\n"

#define FILE_FAILURE        -1
#define FILE_SUCCESS         0

#define INT_INIT             0
#define COLS_DELIMIN        ','
#define ROW_DELIMIN         '\n'

#define FPRINTF_ERROR        0
#define REMOVE_ERROR         0
#define FREAD_SUCCESS        1

// declare functions
void size_file(char *filename, int *size);
void size_line(char *filename, int index, int *size);
char *file_to_buf(char *filename, char *buf, int size);
int buf_to_file(FILE *fp, char *string);
int create_file(char *filename, char *data);
int append_file(char *filename, char *data);
int insert_line_file(char *filename, char *data, int index);
int remove_line_file(char *filename, int index);
int delete_file(char *filename);
char *cpy_line_file(char *filename, int index, char *buf);
int *find_index_file(char *filename, char *needle);

#endif /* FILES_H */