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
 * @brief create_file() creates a file or overwrite an existing file. Write 
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
 * @brief append_file() opens an existing file and append data to the end 
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
 * for the line with a matching string in the first word.
 * 
 * @param filename string representing the name of the file
 * @param word word to find in file, must be null terminated
 * @param line_len the maximum length of each line in the file
 * @return FILE_FAILURE on failure, line index on success
 */
int find_line_file(char *filename, char *word, int line_len)
{
    // declare variables
    FILE *fp;
    char line[line_len];
    int word_len;
    int index;
    int i;
    int counter;

    // initialize variables
    line[line_len] = INT_INIT;
    index = INT_INIT;

    // find length of word to find
    find_string_length(word, &word_len);

    // open file
    fp = fopen(filename, "r");
    if (POINTER_ERROR == fp)
    {
        perror("unable to open file");
        return FILE_FAILURE;
    }

    // store each line into buffer
    while (fgets(line, line_len, fp) != NULL) 
    {
        // initialize counter
        counter = 0;

        // check the first few bytes of the line
        for (i = 0; i < word_len; i++)
        {
            // if matching bytes, increment counter
            if (line[i] == word[i])
            {
                counter++;
            }
        }
        // check one more byte, ensure it matches the deliminator
        if (DELIMIN == line[i])
        {
            counter++;
        }

        // break if word matches
        if (counter == (word_len + 1))
        {
            fclose(fp);
            return index;
        }

        // increment row value
        index++;
    }

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