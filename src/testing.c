// libraries
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "helper.h"
#include "files.h"
#include "testing.h"

// testings the file functions
void file_success(void)
{ 
    // testing create_file
    char *filename = "file_testing.txt";
    printf("\nTESTING CREATE\n");
    if (create_file(filename, FILE_HEADER) == FILE_FAILURE)
    {
        return;
    }

    // testing append_file
    printf("\nTESTING APPEND\n");
    if (append_file(filename, "1111,joe jones,115th,/\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "2222,amy hilman,766 building,yes\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "3333, alex xxd,1234th street,1234\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "4444,the rock,1234,rainbows\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "1234,12th man ,fort hill,sorry\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "2341,DAN HOOVER,washington road ,\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "3412,,yes,idk \n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "1122,1234, ,?\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "2233,1234tina belcher,somewhere,nyc \n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "4433,louis belcher,somewhat, NYC\n") == FILE_FAILURE)
    {
        return;
    }
    if (append_file(filename, "4213,gene belcher,somehow,1234\n") == FILE_FAILURE)
    {
        return;
    }

    // testing size_file
    int file_len;
    printf("\nTESTING SIZE_FILE\n");
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        return;
    }
    printf("file size: %d\n", file_len);

    // testing file_to_buf
    printf("\nTESTING FILE_TO_BUF\n");
    char *buf = calloc(file_len + 1, sizeof(char));
    buf = file_to_buf(filename, buf, file_len);
    if (NULL == buf)
    {
        return;
    }
    printf("file contents: \n%s\n", buf);
    free(buf);

    // testing size_line
    printf("\nTESTING SIZE_LINE\n");
    int line_len;
    int index = 2;
    size_line(filename, index, &line_len);
    if (INT_INIT >= line_len)
    {
        return;
    }
    printf("line[%d]\tline size: %d\n", index, line_len);

    // testing remove_line_file
    printf("\nTESTING REMOVE_LINE\n");
    if(remove_line_file(filename, index) == FILE_FAILURE)
    {
        return;
    }
    printf("removing line[%d]\n", index);
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        return;
    }
    char *buf2 = calloc(file_len + 1, sizeof(char));
    buf2 = file_to_buf(filename, buf2, file_len);
    if (NULL == buf)
    {
        return;
    }
    printf("file contents: \n%s\n", buf2);
    free(buf2);


    // testing insert_line_file
    printf("\nTESTING INSERT_LINE\n");
    char *data = "\n1542,new user, 100 lane road, WA\n";
    if(insert_line_file(filename, data, index) == FILE_FAILURE)
    {
        return;
    }
    printf("\ninserting line[%d]\tdata: %s", index, data);
    size_file(filename, &file_len);
    if (INT_INIT >= file_len)
    {
        return;
    }
    char *buf3 = calloc(file_len + 1, sizeof(char));
    buf3 = file_to_buf(filename, buf3, file_len);
    if (NULL == buf)
    {
        return;
    }
    printf("\nfile contents: \n%s\n", buf3);
    free(buf3);

    // testing reading a line
    printf("\nTESTING COPYING LINE\n");
    line_len = 0;
    index = 4;
    size_line(filename, index, &line_len);
    char *buf4 = calloc(line_len+1, sizeof(char));
    buf4 = cpy_line_file(filename, index, buf4);
    printf("Line[%d]: %s\n", index, buf4);
    free(buf4);

    // testing delete_file
    printf("\nTESTING REMOVING FILE\n");
    if (delete_file(filename) == FILE_FAILURE)
    {
        return;
    }
}