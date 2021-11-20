/**
 * @file files.c
 * @author Anna DeVries
 * @brief source contains all file logic for program
 * @date 2021-11-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

///////// Question for mentor /////////
// is it better to open/close frequently or open/close once?

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "files.h"
#include "helper.h"

/**
 * @brief write_string() writes a string to a file.
 * 
 * @param fp file pointer
 * @param string string to be written to the file
 * @returns FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int write_string_file(FILE *fp, char *string)
{
    // write string to file
    if (FPRINTF_ERROR > fprintf(fp, "%s", string))
    {
        perror("unable to write string to file");
        return FILE_FAILURE;
    }

    // return success
    return FILE_SUCCESS;
}

/**
 * @brief create_file() creates a file or overwrites an existing file. Write 
 * data to file.
 * 
 * @param filename string representing the name of the file
 * @param data data to be written to the file
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int create_file(char *filename, char *data)
{
    // declare variables
    FILE *fp;

    // open file
    fp = fopen(filename, "w");
    if (POINTER_ERROR == fp)
    {
        perror("unable to open file");
        return FILE_FAILURE;
    }

    // write content
    if (FILE_FAILURE == write_string_file(fp, data))
    {
        // close file
        fclose(fp);

        // return error
        return FILE_FAILURE;
    }

    // close file
    fclose(fp);

    // return success
    return FILE_SUCCESS;
}

/**
 * @brief append_file() opens an existing file and appends data to the end 
 * of the file.
 * 
 * @param filename string representing the name of the file
 * @param data data to be appended to file
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int append_file(char *filename, char *data)
{
    // declare variables
    FILE *fp;

    // open file
    fp = fopen(filename, "a");
    if (POINTER_ERROR == fp)
    {
        perror("unable to open file");
        return FILE_FAILURE;
    }

    // write content
    if (FILE_FAILURE == write_string_file(fp, data))
    {
        // close file
        fclose(fp);

        // return error
        return FILE_FAILURE;
    }

    // close file
    fclose(fp);

    // return success
    return FILE_SUCCESS;
}

// /**
//  * @brief insert_file() opens an existing file and inserts data at a given
//  * index in the file.
//  * 
//  * @param filename string representing the name of the file
//  * @param data data to be appended to file
//  * @param index index at which data is inserted
//  * @return FILE_FAILURE on failure, FILE_SUCCESS on success
//  */
// int insert_file(char *filename, char *data, int index)
// {
//     return FILE_SUCCESS;
// }

// /**
//  * @brief remove_line_file() opens an existing file and removes data at a 
//  * given index in the file.
//  * 
//  * @param filename string representing the name of the file
//  * @param index index at which data is deleted
//  * @return FILE_FAILURE on failure, FILE_SUCCESS on success
//  */
// int remove_line_file(char *filename, int index)
// {
//     return FILE_SUCCESS;
// }

/**
 * @brief find_line_file() opens an existing file and searches file contents
 * for the line with a matching string in the first word. It finds all instances
 * of the word in the file.
 * 
 * @param filename string representing the name of the file
 * @param word word to find in file, must be null terminated
 * @return FILE_FAILURE on failure, [row index, column index] pairs of each line
 * containing the word on success
 */
int find_line_file(char *filename, char *word)
{
    // declare variables
    FILE *fp;
    int word_len;
    int character;
    int rows_i;
    int cols_i;
    int index;
    int flag;

    // find length of word to find
    find_string_length(word, &word_len);

    // open file
    fp = fopen(filename, "r");
    if (POINTER_ERROR == fp)
    {
        perror("unable to open file");
        return FILE_FAILURE;
    }

    // initialize variables
    rows_i = INT_INIT;
    cols_i = INT_INIT;
    index = INT_INIT;
    flag = INT_INIT;

    // create 2D array
    int **found_entries = (int **) create_2D_array(1, 2, sizeof(int));
    int n_rows = 0;

    // loop through all characters in file
    while ((character = fgetc(fp)) != EOF) 
    {
        // find new row
        if(character == '\n') 
        {
            // if word found, save column and row
            if (flag == word_len)
            {
                printf("FOUND - row: %d\tcolumn: %d\n", rows_i, cols_i);
            }

            // zero out word index, flag count and column index
            cols_i = INT_INIT;
            index = INT_INIT;
            flag = INT_INIT;

            // increment row counter
            rows_i++;
        }

        // find new column
        else if(character == DELIMIN)
        {
            // if word found, save column and row
            if (flag == word_len)
            {
                found_entries[n_rows][0] = rows_i;
                found_entries[n_rows][1] = cols_i;
                printf("FOUND - row: %d\tcolumn: %d\n", rows_i, cols_i);
            }

            // zero out word index and flag count
            index = INT_INIT;
            flag = INT_INIT;

            // increment column index
            cols_i++;
        }

        // read each word
        else
        {
            // compare words of the same length to the word being searched
            if (index < word_len)
            {
                // increment flag counter if there is a match
                if (character == word[index])
                {
                    flag++;
                }
            }
            // if the word is too long, zero out the flag
            else
            {
                flag = INT_INIT;
            }
            index++;
        }
    }

    for (int i = 0; i <= n_rows; i++)
    {
        printf("Entry[%d] - rows: %d\tcolumns: %d\n", n_rows, found_entries[0][0], found_entries[0][1]);
    }

    // free memory
    destroy_array((void **)found_entries, 1);

    // close file
    fclose(fp);

    // unable to find matching word
    return FILE_FAILURE;
}

// /**
//  * @brief pull_line_file() opens an existing file and returns the contents
//  * of a line at a given index.
//  * 
//  * @param filename string representing the name of the file
//  * @param index at which data is insterted
//  * @return FILE_FAILURE on failure, line index on success
//  */
// char *pull_line_file(char *filename, int index)
// {
//     return FILE_SUCCESS;
// }

/**
 * @brief delete_file() deletes an existing file.
 *  
 * @param filename name of the file
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
**/
int delete_file(char *filename)
{
    // remove file
    if(remove(filename) != REMOVE_ERROR)
    {
        perror("unable to remove file");
        return FILE_FAILURE;
    }

    // return success
    return FILE_SUCCESS;
}