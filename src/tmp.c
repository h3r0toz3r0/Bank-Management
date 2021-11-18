// libraries
#include "tmp.h"
#include <stdio.h>

int transact(void)
{
    printf("transact()\n");

    // return success
    return TRANSACT_SUCCESS;
}

int view(void)
{
    printf("view()\n");

    // return success
    return VIEW_SUCCESS;
}

int create(void)
{
    printf("create()\n");

    // return success
    return CREATE_SUCCESS;
}

int edit(void)
{
    printf("edit()\n");

    // return success
    return EDIT_SUCCESS;
}

int erase(void)
{
    printf("erase()\n");

    // return success
    return ERASE_SUCCESS;
}