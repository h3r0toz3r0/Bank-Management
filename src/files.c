/**
 * @name find_customer.c
 * @author Anna DeVries
 * @brief this file provides functions for file operations.
 */

// libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files.h"
#include "helper.h"
#include "customer.h"

/**
 * @brief find_customer() searches the records file for a specific account number.
 * @param accn - interger that holds the account number to be searched.
 * @param line_cpy - empty string to place customer string object into.
 * @returns customer entry matching the account number.
 * @retval line_cpy - success
 * @retval FIND_CUSTOMER_ERROR - error
 */
char *find_customer(int accn, char *line_cpy)
{
    // declare variables
    FILE *fp;
    char *line;
    size_t len;
    ssize_t read;
    char *ptr;
    int count;

    // initiate variables 
    len = INIT_INTEGER;
    line = INIT_STRING;

    // open file
    fp = fopen(FILE_PATH, "r");
    if (fp == FOPEN_ERROR)
    {
        // print error msg
        printf("\nfopen failed; unable to find customer.\n");

        // free memory
        free(line);

        // return error
        return FIND_CUSTOMER_ERROR;
    }
    
    // read file line by line
    while ((read = getline(&line, &len, fp)) != END_FILE)
    {
        // initialize count 
        count = INIT_INTEGER;

        // copy line 
        strcpy(line_cpy, line);

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

                    // free memory
                    free(line);

                    // load string into return 
                    return line_cpy;
                }
            }
        }
    }

    // close file
    fclose(fp);

    // free memory
    free(line);

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

/**
 * @brief exists() checks if the file exists in the computer system.
 * @param filename - string that holds the name of the file.
 * @returns a value expressing if the file exists or not.
 * @retval FILE_EXISTS - file exists.
 * @retval FILE_DNE - file doesn't exist.
 */
int exists(char *filename)
{
    // declare variables
    FILE *fp;

    // open file
    if ((fp = fopen(filename, "r")))
    {
        // close file if it exists
        fclose(fp);
        
        // return file exists
        return FILE_EXISTS;
    }

    // return file DNE
    return FILE_DNE;
}

/**
 * @brief delete_line() deletes a single line from the file based on accn.
 * @param accn - integer that represents account number to be removed.
 * @param filename - filename for the records file.
 * @returns a value expressing if removing line was successful.
 * @retval DELETE_LINE_SUCCESS - success.
 * @retval DELETE_LINE_ERROR - error.
 */
int delete_line(int accn, char *filename)
{
    // declare variables
    FILE *fp1;
    FILE *fp2;
    int length_customer_obj;
    char *ptr;
    int cust_accn;

    // initialize variables
    length_customer_obj =       SIZE_NAME + SIZE_STREET + SIZE_CITY + 
                                SIZE_STATE + SIZE_PHONE + SIZE_SSN + 
                                SIZE_MONTH + SIZE_DAY + SIZE_YEAR + 
                                SIZE_TYPE;
    char line[length_customer_obj];
    char line_cpy[length_customer_obj];
    cust_accn = INIT_INTEGER;

    // open files
    fp1 = fopen(filename, "r");
    if (fp1 == FOPEN_ERROR)
    {
        printf("\nfopen failed; unable to find file.\n");
        return DELETE_LINE_ERROR;
    }
    fp2 = fopen(FILE_TMP_PATH, "w");
    if (fp2 == FOPEN_ERROR)
    {
        printf("\nfopen failed; unable to open file.\n");
        return DELETE_LINE_ERROR;
    }

    // copy content into tmp
    while (!feof(fp1))
    {
        strcpy(line, "\0");
        fgets(line, length_customer_obj, fp1);

        // copy line 
        strcpy(line_cpy, line);

        if (!feof(fp1)) 
        {
            // read accn number of line
            ptr = strtok(line,",");
            cust_accn = atoi(ptr);

            // skip line of customer to delete
            if (cust_accn != accn) 
            {
                fprintf(fp2, "%s", line_cpy);
            }
        }
    }

    // close files
    fclose(fp1);
    fclose(fp2);

    // remove file
    if (remove(FILE_PATH) != REMOVE_SUCCESS)
    {
        printf("\nremove() failed; unable to remove temporary file.\n");
    }

    // rename file
    if (rename(FILE_TMP_PATH, FILE_PATH) != RENAME_SUCCESS)
    {
        printf("\nrename() failed; unable to rename temporary file.\n");
    }

    // return error
    return DELETE_LINE_SUCCESS;
}