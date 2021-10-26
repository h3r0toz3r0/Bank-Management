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
    char *ptr;
    int count;

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
    
    // read file line by line
    while ((read = getline(&line, &len, fp)) != END_FILE)
    {
        // initialize count 
        count = INIT_INTEGER;

        // break apart line by commas
        ptr = strtok(line,",");
        while (ptr != NULL)
        {
            int a = atoi(ptr);
            ptr = strtok(NULL, ",");
            count++;

            // compare account number
            if (count == ACCN_ITERATION)
            {
                if (a == accn)
                {
                    // close file
                    fclose(fp);

                    // load string into return 
                    return line;
                }
            }
        }
    }

    // close file
    fclose(fp);

    // free memory
    if (line)
    {
        free(line);
    }

    // return success
    return FIND_CUSTOMER_ERROR;
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
 * @brief write_string() function writes strings to file.
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
 * @param cust_string - string object of the customer 
 * @returns success or error messages.
 * @retval INIT_FILE_SUCCESS - success.
 * @retval INIT_FILE_ERROR - error.
 */
int insert_file(char *cust_string)
{
    // declare variables 
    FILE *fp;

    // open file
    fp = fopen(FILE_PATH, "a");
    if (fp == FOPEN_ERROR)
    {
        printf("\nfopen failed; unable to save customer information.\n");
        return INIT_FILE_ERROR;
    }

    // add account to FILE
    if (write_string(fp, cust_string) == WRITE_ERROR)
    {
        // close file
        if (fclose(fp) == EOF)
        {
            printf("\nfclose failed; unable to save customer information.\n");
            return INIT_FILE_ERROR;
        }

        printf("\ninsert_file() failed; unable to save customer information.\n");
        return INIT_FILE_ERROR;
    }

    // close file
    if (fclose(fp) == EOF)
    {
        printf("\nfclose failed; unable to save customer information.\n");
        return INIT_FILE_ERROR;
    }

    // return success
    return INIT_FILE_SUCCESS;
}