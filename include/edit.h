/**
 * @file edit.h
 * @author Anna DeVries
 * @brief header file for edit.c
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// include guard
#ifndef EDIT_H
#define EDIT_H

// macros 
#define EDIT_FAILURE           -1
#define EDIT_SUCCESS            0

#define SELECTION_PHONE         1
#define SELECTION_ADDRESS       2

// declare functions
int edit(void);

#endif /* EDIT_H */