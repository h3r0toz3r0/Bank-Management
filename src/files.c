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
#include "files.h"

/**
 * @brief size_file() determines the size of the file.
 * 
 * @param filename string representing the name of the file
 * @param size size of file, passed by reference to function;
 *            res = 0 on error
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
        perror("unable to open file");
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
 * @param index at which data is insterted
 * @param size size of file, passed by reference to function;
 *            res = 0 on error
 */
void size_line(char *filename, int index, int *size)
{
    // declare variables
    FILE *fp;
    char character;
    int count;

    // initialize variables
    *size = INT_INIT;
    count = INT_INIT;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        perror("unable to open file");
        return;
    }

    // get all characters of the file
    while ((character = fgetc(fp)) != EOF)
    {
        // check for new line
        if (character == ROW_DELIMIN)
        {
            // count lines
            count++;
        }

        // check if line matches index
        if (count == index)
        {
            // count size of line
            *size += 1;
        }

        // once index is passed
        else if (count > index)
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
 * @param buf char* buffer to hold the contents
 * @param size size of the file and buffer
 * @return the buffer with the file contents on success; NULL on 
 * error
 */
char *file_to_buf(char *filename, char *buf, int size)
{
    // declare variables
    FILE *fp;

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        perror("unable to open file");
        return NULL;
    }

    // write file to buffer
    if (fread(buf, size, 1, fp) != FREAD_SUCCESS)
    {
        // print error message
        perror("fread failed");

        // close file
        fclose(fp);

        // return error
        return NULL;
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
    if (NULL == fp)
    {
        perror("unable to open file");
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
        perror("unable to open file");
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
    printf("DEBUGGING INSERT LINE\nfilename: %s\tdata: %s\tindex: %d\n\n", filename, data, index);
    return FILE_SUCCESS;
}

/**
 * @brief remove_line_file() opens an existing file and removes data at a 
 * given index in the file.
 * 
 * @param filename string representing the name of the file
 * @param index index at which data is deleted
 * @return FILE_FAILURE on failure, FILE_SUCCESS on success
 */
int remove_line_file(char *filename, int index)
{
    printf("DEBUGGING REMOVE LINE\nfilename: %s\tindex: %d\n\n", filename, index);
    
    // declare variables
    FILE *fp;
    char *buf;
    int file_len;

    // initialize variables
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        return FILE_FAILURE;
    }

    // open file
    fp = fopen(filename, "r");
    if (NULL == fp)
    {
        perror("unable to open file");
        return FILE_FAILURE;
    }

    // allocate memory
    buf = calloc(file_len, sizeof(char));

    // copy each character into buffer
        // skip line matching index
        // count line number

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
        perror("unable to remove file");
        return FILE_FAILURE;
    }

    // return success
    return FILE_SUCCESS;
}