/**
 * @brief tmp - header file for tmp.c.
 */

// include guard
#ifndef TMP_H
#define TMP_H   

// macros
#define EDIT_ERROR             -1
#define EDIT_SUCCESS            0
#define TRANSACT_ERROR         -1
#define TRANSACT_SUCCESS        0

// declare functions
int edit(void);
int transact(void);

#endif /* TMP_H */