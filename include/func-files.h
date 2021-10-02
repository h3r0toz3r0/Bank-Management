/*
 * name: func-files.h
 * description: header file for func-file.c 
 */

//  include guard
#ifndef FILES_H
#define FILES_H   

//  includes
#include "struct-cust.h"

//  macros
#define FILE_PATH   "records.csv"

//  declare function
void insert_file(struct Customer* customer);
int assign_acc(void);

#endif /* FILES_H */
