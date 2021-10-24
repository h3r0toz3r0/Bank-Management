/**
 * @brief create.h - header file for create.c.
 */

// include guard
#ifndef CREATE_H
#define CREATE_H    

// libraries
#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "helper.h"
#include "files.h"

// macros 
#define CREATE_ERROR           -1
#define CREATE_SUCCESS          0

#define INIT_CHECK              0
#define EXIT_CHECK              1
#define SIZE_INPUT              4
#define RANDSIZE                6
#define RAND_MAX                999999
#define RAND_MIN                111111
#define INIT_CUST               NULL

// declare functions
int create(void);

#endif /* CREATE_H */