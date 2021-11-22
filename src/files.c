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
 * @brief find_line_file() opens an existing file and searches the file for all instances
 * of a specific word.
 * 
 * @param filename string representing the name of the file
 * @param word word to find in file, must be null terminated
 * @return NULL on failure, array of [row index, column index] pairs of each line
 * containing the word on success
 */
void **find_line_file(char *filename, char *word, void **found_words)
{
    // declare variables
    FILE *fp;
    int keyword_len;    // length of keyword being searched for
    int word_len;       // length of word read from file
    int rows_i;         // running row count of file
    int cols_i;         // running column count of file
    int flag;
    int character;
    int n_rows;
    int n_columns;
    int entry;

    // find length of word to find
    find_string_length(word, &keyword_len);

    // open file
    fp = fopen(filename, "r");
    if (POINTER_ERROR == fp)
    {
        perror("unable to open file");
        return NULL;
    }

    // initialize variables
    rows_i = INT_INIT;
    cols_i = INT_INIT;
    word_len = INT_INIT;
    flag = INT_INIT;
    entry = INT_INIT;
    n_rows = N_ROWS;
    n_columns = N_COLS;

    // read all characters in a file
    while ((character = fgetc(fp)) != EOF) 
    {
        // new row
        if(character == ROW_DELIMIN) 
        {
            // words match; add entry to array
            if (flag == keyword_len)
            {
                // reallocate array as needed
                if ((entry + 1) == n_rows)
                {
                    found_words = (int **) increase_rows_array((void **) found_words, n_rows, 1, n_columns, sizeof(int));
                    if (found_words == NULL)
                    {
                        // free memory
                        destroy_2D_array((void**) found_words, n_rows);

                        // close file
                        fclose(fp);

                        // return failure
                        return NULL;
                    }
                    n_rows++;
                }

                // update array of row x column pairs
                found_words[entry][0] = rows_i;
                found_words[entry][1] = cols_i;

                // increment entry of the array
                entry++;
            }

            // zero out necessary variables
            cols_i = INT_INIT;
            word_len = INT_INIT;
            flag = INT_INIT;

            // increment row counter
            rows_i++;
        }

        // new column
        else if(character == COLS_DELIMIN)
        {
            // words match; add entry to array
            if (flag == keyword_len)
            {
                // reallocate array as needed
                if ((entry + 1) == n_rows)
                {
                    found_words = (int **) increase_rows_array((void **) found_words, n_rows, 1, n_columns, sizeof(int));
                    if (found_words == NULL)
                    {
                        // free memory
                        destroy_2D_array((void**) found_words, n_rows);

                        // close file
                        fclose(fp);

                        // return failure
                        return NULL;
                    }
                    n_rows++;
                }

                // update array of row x column pairs
                found_words[entry][0] = rows_i;
                found_words[entry][1] = cols_i;

                // increment entry of the array
                entry++;
            }

            // zero out necessary variables
            word_len = INT_INIT;
            flag = INT_INIT;

            // increment column index
            cols_i++;
        }

        // new word
        else
        {
            // compare word length to the keyword length for a match
            if (word_len < keyword_len)
            {
                // increment flag counter if there is a match
                if (character == word[word_len])
                {
                    flag++;
                }
            }
            // if the word is too long, zero out the flag
            else
            {
                flag = INT_INIT;
            }

            // increment word length from file
            word_len++;
        }
    }

    // close file
    fclose(fp);

    // return found words
    return found_words;
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