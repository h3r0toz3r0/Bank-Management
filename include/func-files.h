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
void assign_acc(struct Customer* customer);
void unique_file(int seed, struct Customer* customer);

#endif /* FILES_H */
