/**
 * @name main.c
 * @author Anna DeVries
 * @brief bank management program
 */

// libraries
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "helper.h"
#include "files.h"

int main(void)
{
    // testing create_file
    char *filename = "file_testing.txt";
    if (create_file(filename, FILE_HEADER) == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }

    // testing append_file
    if (append_file(filename, "1111,joe jones,115th,/\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "2222,amy hilman,766 building,yes\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "3333, alex xxd,1234th street,1234\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "4444,the rock,1234,rainbows\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "1234,12th man ,fort hill,sorry\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "2341,DAN HOOVER,washington road ,\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "3412,,yes,idk \n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "1122,1234, ,?\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "2233,1234tina belcher,somewhere,nyc \n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "4433,louis belcher,somewhat, NYC\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    if (append_file(filename, "4213,gene belcher,somehow,1234\n") == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }

    // testing size_file
    int file_len;
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        exit(EXIT_FAILURE);
    }
    printf("\nfile size: %d\n", file_len);

    // testing file_to_buf
    char *buf = calloc(file_len + 1, sizeof(char));
    buf = file_to_buf(filename, buf, file_len);
    if (NULL == buf)
    {
        exit(EXIT_FAILURE);
    }
    printf("file contents: \n%s\n", buf);
    free(buf);

    // testing size_line
    int line_len;
    int index = 2;
    size_line(filename, index, &line_len);
    if (INT_INIT >= line_len)
    {
        exit(EXIT_FAILURE);
    }
    printf("\nline[%d]\tline size: %d\n", index, line_len);

    // testing remove_line_file
    if(remove_line_file(filename, index) == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    printf("\nremoving line[%d]\n", index);
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        exit(EXIT_FAILURE);
    }
    char *buf2 = calloc(file_len + 1, sizeof(char));
    buf2 = file_to_buf(filename, buf2, file_len);
    if (NULL == buf)
    {
        exit(EXIT_FAILURE);
    }
    printf("file contents: \n%s\n", buf2);
    free(buf2);


    // testing insert_line_file
    char *data = "\n1542,new user, 100 lane road, WA\n";
    if(insert_line_file(filename, data, index) == FILE_FAILURE)
    {
        exit(EXIT_FAILURE);
    }
    printf("\ninserting line[%d]\tdata: %s", index, data);
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        exit(EXIT_FAILURE);
    }
    char *buf3 = calloc(file_len + 1, sizeof(char));
    buf3 = file_to_buf(filename, buf3, file_len);
    if (NULL == buf)
    {
        exit(EXIT_FAILURE);
    }
    printf("file contents: \n%s\n", buf3);
    free(buf3);

    // // testing delete_file
    // if (delete_file(filename) == FILE_FAILURE)
    // {
    //     exit(EXIT_FAILURE);
    // }
    

    // // declare variables
    // int select_bit;

    // // initiate variables
    // select_bit = ERROR_SELECTION;

    // // initialize records file
    // if (create_file(FILE_PATH, FILE_HEADER) == FILE_FAILURE)
    // {
    //     exit(EXIT_FAILURE);
    // }

    // // for-loop till user chooses to exit
    // while (select_bit != EXIT_SELECTION)
    // {
    //     // prints welcome screen
    //     printf("\n\t--------------- CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM ---------------\n");
    //     printf("\n\tOPTIONS:\t%d - create a new account\n"
    //         "\t\t\t%d - update an existing account\n"
    //         "\t\t\t%d - remove existing account\n"
    //         "\t\t\t%d - deposit/withdraw from an account\n"
    //         "\t\t\t%d - view account information associated with account\n"
    //         "\t\t\t%d - exit\n\n", 
    //         CREATE_SELECTION, EDIT_SELECTION, ERASE_SELECTION,
    //         TRANSACT_SELECTION, VIEW_SELECTION, EXIT_SELECTION);

    //     // user input
    //     printf("Enter a number: ");
    //     integer_input(&select_bit);
    //     if(select_bit == ERROR_SELECTION)
    //     {
    //         printf("\nInteger_input() failed; unable to take user input.\n");
    //         exit(EXIT_FAILURE);
    //     }

    //     // check select_bit for bank functionality
    //     // BankSystem runs regardless of error status for selection
    //     selection(select_bit);

    //     // zero out select_bit
    //     if (select_bit != EXIT_SELECTION)
    //     {
    //         select_bit = ERROR_SELECTION;
    //     }
    // }

    // int random = 0;
    // random_gen(&random);
    // printf("Random Number: %d\n", random);

    // // exit message
    // printf("\n\tTHANK YOU FOR USING THE BANK MANAGEMENT SYSTEM."
    //         "\n\tHAVE A GOOD DAY.\n\n");

    // exit gracefully
    exit(EXIT_SUCCESS);
}