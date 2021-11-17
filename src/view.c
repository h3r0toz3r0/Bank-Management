/**
 * @name view.c
 * @brief this function views and prints the customer information.
 * @retval VIEW_SUCCESS - success.
 * @retval VIEW_ERROR - error.
 */

// libraries
#include <stdio.h>
#include "view.h"

int view(void)
{
    printf("\n------------- VIEW ACCOUNT -------------\n");

    // return success
    printf("Returning to main menu.\n\n");
    return VIEW_SUCCESS;
}
