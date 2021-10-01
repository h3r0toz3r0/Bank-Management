/*
 * name: main.h
 * description: header file for main.c 
 */

//  include guard
#ifndef MAIN_H
#define MAIN_H    

//  includes
#include "new-acc.h"
#include "edit.h"
#include "transact.h"
#include "see.h"
#include "erase.h"
#include "view-list.h"
#include <stdio.h>

//  declare functions
int new_acc(void);
void edit(void);
void erase(void);
void see(void);
void transact(void);
void view_list(void);

#endif /* MAIN_H */