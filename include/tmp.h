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

// declare functions
int transact(void);
int view(void);

#endif /* TMP_H */