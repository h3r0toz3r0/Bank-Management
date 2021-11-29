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
 * @brief size_file() determines the size of the file in bytes.
 * 
 * @param filename string representing the name of the file
 * @param size size of file, passed by reference to function; size = 0 on error
 */
void size_file(char *filename, int *size)
{
    // declare variables
    FILE *fp;
    char character;

    // initialize variables
    *size = INT_INIT;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return
        return;
    }

    // obtain each character in file
    while ((character = fgetc(fp)) != EOF)
    {
        // increase size
        *size += 1;
    }

    // close file
    fclose(fp);

    // return
    return;
}

/**
 * @brief size_line() determines the size of a particular line
 * in a file.
 * 
 * @param filename string representing the name of the file
 * @param index line number in file
 * @param size size of file, passed by reference to function; size = 0 on error
 */
void size_line(char *filename, int index, int *size)
{
    // declare variables
    FILE *fp;
    char character;
    int line_count;

    // initialize variables
    *size = INT_INIT;
    line_count = INT_INIT;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return
        return;
    }

    // get all characters of the file
    while ((character = fgetc(fp)) != EOF)
    {
        // check for new line
        if (character == ROW_DELIMIN)
        {
            // count lines
            line_count++;
        }

        // check if line matches index
        if (line_count == index)
        {
            // count size of line
            *size += 1;
        }

        // once index is passed
        else if (line_count > index)
        {
            // close file
            fclose(fp);

            // return
            return;
        }
    }

    // close file
    fclose(fp);

    // return
    return;
}

/**
 * @brief file_to_buf() writes the content of the file to a buffer.
 * 
 * @param filename string representing the name of the file
 * @param buf buffer holding content of file
 * @param size size of the file and buffer
 * @return the buffer with the file contents on success; STR_INPUT_FAILURE 
 * on error
 */
char *file_to_buf(char *filename, char *buf, int size)
{
    // declare variables
    FILE *fp;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return error
        return buf;
    }

    // write file to buffer
    if (fread(buf, size, 1, fp) != FREAD_SUCCESS)
    {
        // print error message
        perror("fread failed");

        // close file
        fclose(fp);

        // return error
        return buf;
    }

    // close file
    fclose(fp);

    // return buf
    return buf;
}

/**
 * @brief buf_to_file() writes a string to a file.
 * 
 * @param fp file pointer
 * @param string string to be written to the file
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int buf_to_file(FILE *fp, char *string)
{
    // write string to file
    if (FPRINTF_ERROR > fprintf(fp, "%s", string))
    {
        // print error message
        perror("unable to write string to file");

        // return error
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
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return error
        return FILE_FAILURE;
    }

    // write content
    if (FILE_FAILURE == buf_to_file(fp, data))
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
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return error
        return FILE_FAILURE;
    }

    // write content
    if (FILE_FAILURE == buf_to_file(fp, data))
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
 * @brief insert_line_file() opens an existing file and inserts data at a given
 * index in the file.
 * 
 * @param filename string representing the name of the file
 * @param data data to be appended to file
 * @param index index at which data is inserted
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int insert_line_file(char *filename, char *data, int index)
{
    // declare variables
    FILE *fp;
    char *buf;
    int file_len;       // length of original file
    int line_len;       // length of new data
    int character_len;  // length to track location within buffer
    int total_length;   // total length of new buffer
    char character;
    int line;           // line count; for indexing

    // initialize variables
    line = INT_INIT;
    character_len = INT_INIT;
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        return FILE_FAILURE;
    }
    find_string_length(data, &line_len);
    total_length = file_len + line_len;

    printf("line length: %d\n\n", line_len);

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error message
        perror("unable to open file");

        // return error
        return FILE_FAILURE;
    }

    // allocate memory
    buf = calloc(total_length, sizeof(char));
    if (NULL == buf)
    {
        // print error message
        perror("unable to allocate memory");

        // close file
        fclose(fp);

        // return error
        return FILE_FAILURE;
    }

    // get all characters of the file
    while ((character = fgetc(fp)) != EOF)
    {
        // find new lines
        if (character == ROW_DELIMIN)
        {
            // count lines
            line++;
        }

        // once index is found
        if (index == line)
        {
            // copy new line into buffer
            if (snprintf(buf + character_len, line_len, "%s", data) < INT_INIT)
            {
                // close file
                fclose(fp);

                // free memory
                free(buf);

                // return error
                return FILE_FAILURE;
            }

            // increment line count
            line++;
        }

        // copy each character into buffer
        if (strncat(buf, &character, 1) == NULL)
        {
            // close file
            fclose(fp);

            // free memory
            free(buf);

            // return error
            return FILE_FAILURE;
        }

        // increment buffer location
        character_len++;
    }

    // close file
    fclose(fp);

    // re-write new buffer into file
    if (create_file(filename, buf) == FILE_FAILURE)
    {
        // free memory
        free(buf);

        // return error
        return FILE_FAILURE;
    }

    // free memory
    free(buf);

    // return success    
    return FILE_SUCCESS;
}

/**
 * @brief remove_line_file() opens an existing file and removes data at a 
 * given index in the file.
 * 
 * @param filename string representing the name of the file
 * @param index line number to be removed
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int remove_line_file(char *filename, int index)
{  
    // declare variables
    FILE *fp;
    char *buf;
    int file_len;
    char character;
    int line;

    // initialize variables
    line = INT_INIT;
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        // return error
        return FILE_FAILURE;
    }

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error message
        perror("unable to open file");

        // return error
        return FILE_FAILURE;
    }

    // allocate memory
    buf = calloc(file_len, sizeof(char));
    if (NULL == buf)
    {
        // print error message
        perror("unable to allocate memory");

        // close file
        fclose(fp);

        // return error
        return FILE_FAILURE;
    }

    // get all characters of the file
    while ((character = fgetc(fp)) != EOF)
    {
        // find new lines
        if (character == ROW_DELIMIN)
        {
            // count lines
            line++;
        }

        // skip line to remove
        if (line != index)
        {
            // copy each character into buffer
            if (strncat(buf, &character, 1) == NULL)
            {
                // close file
                fclose(fp);

                // free memory
                free(buf);

                // return error
                return FILE_FAILURE;
            }
        }
    }

    // close file
    fclose(fp);

    // re-write new buffer into file
    if (create_file(filename, buf) == FILE_FAILURE)
    {
        // free memory
        free(buf);

        // return error
        return FILE_FAILURE;
    }

    // free memory
    free(buf);

    // return success    
    return FILE_SUCCESS;
}

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
        // print error message
        perror("unable to remove file");

        // return error
        return FILE_FAILURE;
    }

    // return success
    return FILE_SUCCESS;
}

/**
 * @brief cpy_line_file() copies a line specified by an index 
 * into a buffer.
 *  
 * @param filename name of the file
 * @param index line index to copy into buffer
 * @param buf buffer to hold line
 * @return STR_INPUT_FAILURE on failure, buffer on success
**/
char *cpy_line_file(char *filename, int index, char *buf)
{
    // declare variables
    FILE *fp;
    char character;
    int line_count;

    // initialize variables
    line_count = INT_INIT;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return
        return buf;
    }

    // get all characters of the file
    while ((character = fgetc(fp)) != EOF)
    {
        // check for new line
        if (character == ROW_DELIMIN)
        {
            // count lines
            line_count++;
        }

        // check if line matches index
        if (line_count == index)
        {
            // copy line into buf
            if (strncat(buf, &character, 1) == NULL)
            {
                // print error message
                perror("unable to copy character into buffer");

                // close file
                fclose(fp);

                // return
                return buf;
            }
        }

        // check if line exceeds index
        if (line_count > index)
        {
            // close file
            fclose(fp);

            // return
            return buf;
        }
    }

    // close file
    fclose(fp);

    // print error message
    printf("unable to find line.\n");

    // return
    return buf;
}

/**
 * @brief find_index_file() finds the column and row number of first instance
 * of needle
 *  
 * @param filename name of the file
 * @param needle the string 
 * @returns integer array as row x column of needle instance; integer array
 *          will return {FILE_FAILURE, FILE_FAILURE} on error
**/
int *find_index_file(char *filename, char *needle)
{
    // declare variables
    static int index[2];
    FILE *fp;
    char character;
    int n_rows;
    int n_columns;
    int word_len;
    int needle_len;
    int flag;

    // initialize variables
    n_rows = INT_INIT;
    n_columns = INT_INIT;
    word_len = INT_INIT;
    flag = INT_INIT;
    index[0] = FILE_FAILURE;
    index[1] = FILE_FAILURE;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        // print error
        perror("unable to open file");

        // return
        return index;
    }

    // find size of needle
    find_string_length(needle, &needle_len);
    if (INT_INIT >= needle_len)
    {
        // close file
        fclose(fp);

        // return
        return index;
    }

    // get all characters of the file
    while ((character = fgetc(fp)) != EOF)
    {
        // count word length
        word_len++;

        // count new rows
        if (character == ROW_DELIMIN)
        {
            n_rows++;

            // compare flag
            if(flag == needle_len)
            {
            printf("needle: %s\t rows: %d\tneedle len: %d\tword len: %d\n", needle, n_rows, needle_len, word_len);
            }

            // reset word count
            word_len = INT_INIT;
        }

        // count new columns
        if (character == COLS_DELIMIN)
        {
            n_columns++;

            // reset word count
            word_len = INT_INIT;
        }

        // check word and needle are within same size
        if ((word_len - 1) <= needle_len)
        {
            flag++;
        }
        else if ((word_len - 1) > needle_len)

        // count characters in word
            // compare character to needle
    }

    // close file
    fclose(fp);

    // return index of needle
    return index;
}