/*
 * name: main.h
 * description: header file for main.c 
 */

//  include guard
#ifndef MAIN_H
#define MAIN_H    

//  includes
#include "func-create.h"
#include "func-edit.h"
#include "func-erase.h"
#include "func-see.h"
#include "func-transact.h"
#include "func-view.h"

//  declare functions
int func_create(void);
void func_edit(void);
void func_erase(void);
void func_see(void);
void func_transact(void);
void func_view(void);

#endif /* MAIN_H */