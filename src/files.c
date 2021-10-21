/**
 * @name find_customer.c
 * @author Anna DeVries
 * @brief this file provides functions for file operations.
 */

// libraries
#include "files.h"

/**
 * @brief 
 * @param
 * @returns 
 * @retval 
 * @retval 
 */
char *find_customer(int accn)
{
    // declare variables
    FILE *fp;
    char *line;
    size_t len;
    ssize_t read;

    //initiate variables
    line = INIT_STRING;
    len = INIT_INTEGER;

    // open file
    fp = fopen(FILE_PATH, "r");
    if (fp == FOPEN_ERROR)
    {
        printf("\nfopen failed; unable to find customer.\n");
        return FIND_CUSTOMER_ERROR;
    }
    
    // read file
    while ((read = getline(&line, &len, fp)) != END_FILE)
    {
        printf("%s\n", line);
    }

    // close file
    fclose(fp);

    // free memory
    if (line)
    {
        free(line);
    }

    printf("tmp print. accn: %d\n", accn);

    // return success
    return "hi";
}

/**
 * @brief write_int() function writes integers to file.
 * @param fp- file pointer.
 * @param num - integer to write to file
 * @returns success or error messages.
 * @retval WRITE_SUCCESS - success.
 * @retval WRITE_ERROR - error.
 */
int write_int(FILE *fp, int num)
{
    // write int to file
    if (fprintf(fp, "%d", num) < FPRINTF_ERROR)
    {
        printf("\nfwrite failed; unable to write integer to file.\n");
        return WRITE_ERROR;
    }

    // return success
    return WRITE_SUCCESS;
}

/**
 * @brief write_string() function writes integers to file.
 * @param fp- file pointer.
 * @param string - message to write to file.
 * @returns success or error messages.
 * @retval WRITE_SUCCESS - success.
 * @retval WRITE_ERROR - error.
 */
int write_string(FILE *fp, char *string)
{
    // write string to file
    if (fprintf(fp, "%s", string) < FPRINTF_ERROR)
    {
        printf("\nfwrite failed; unable to write integer to file.\n");
        return WRITE_ERROR;
    }

    // return success
    return WRITE_SUCCESS;
}

/**
 * @brief insert_file() function inserts new account into file.
 * @returns success or error messages.
 * @retval customer - success.
 * @retval INIT_FILE_ERROR - error.
 */
// int insert_file(struct Customer* customer)
// {
//     // define local variables
//     FILE *fp;

//     // open file
//     fp = fopen(FILE_PATH, "a");
//     if (fp == FOPEN_ERROR)
//     {
//         printf("\nfopen failed; unable to save customer information.\n");
//         return INIT_FILE_ERROR;
//     }

//     // append structure to file
//     if (write_int(fp, customer->acc_num) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, customer->name) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, customer->street) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, customer->city) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, customer->state) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_int(fp, customer->citizenship) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_int(fp, customer->birth_month) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_int(fp, customer->birth_day) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_int(fp, customer->birth_year) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, customer->phone) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, ",") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_int(fp, customer->type) == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }
//     if (write_string(fp, "\n") == WRITE_ERROR)
//     {
//         return INIT_FILE_ERROR;
//     }

//     // close file
//     if (fclose(fp) == EOF)
//     {
//         printf("\nfclose failed; unable to save customer information.\n");
//         return INIT_FILE_ERROR;
//     }

//     // return
//     return 0;
// }