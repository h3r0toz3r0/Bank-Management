/**
 * @name edit.c
 * @brief this function allows the user to update their personal address and phone number.
 * @retval EDIT_SUCCESS - success.
 * @retval EDIT_ERROR - error.
 */

// libraries
#include <stdio.h>
#include "edit.h"

int edit(void)
{
    printf("\n------------- EDIT ACCOUNT -------------\n");

    // return success
    printf("Returning to main menu.\n\n");
    return EDIT_SUCCESS;
}
