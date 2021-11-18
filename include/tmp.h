/**
 * @brief tmp - header file for tmp.c.
 */

// include guard
#ifndef TMP_H
#define TMP_H   

// macros
#define TRANSACT_ERROR         -1
#define TRANSACT_SUCCESS        0

#define VIEW_ERROR             -1
#define VIEW_SUCCESS            0

#define CREATE_ERROR             -1
#define CREATE_SUCCESS            0

#define EDIT_ERROR             -1
#define EDIT_SUCCESS            0

#define ERASE_ERROR             -1
#define ERASE_SUCCESS            0

// declare functions
int transact(void);
int view(void);
int create(void);
int edit(void);
int erase(void);

#endif /* TMP_H */