#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    // create new data-type to store byte of data
    typedef uint8_t BYTE;
    // initialize counter to count number of JPGs found
    int i = 0;
    // allocate memory to hold size of filename
    char *filename = malloc(sizeof(char) * 8);
    // create an array of byte of size 512
    BYTE x[512];
    // initialize file pointer to NULL
    FILE *img = NULL;
    // check for additional command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //open card file for reading
    FILE *ptrr = fopen(argv[1], "r");
    // check if file can be opened
    if (ptrr == NULL)
    {
        printf("File cannot be open.\n");
        return 1;
    }
    // reading data from card in 512byte chunk untill end of file
    while (fread(x, 512, 1, ptrr) == 1)
    {
        // check for start of JPG
        if (x[0] == 0xff && x[1] == 0xd8 && x[2] == 0xff && (x[3] & 0xf0) == 0xe0)
        {
            //check if it is the first JPG found
            if (i == 0)
            {
                // create filename for first JPG found
                sprintf(filename, "%03i.jpg", i);
                // open file for first JPG for writing
                img = fopen(filename, "w");
                // write data to file opened
                fwrite(x, 512, 1, img);
            }
            // check if not first JPG
            else
            {
                //close previous JPG
                fclose(img);
                // create file name for new JPG
                sprintf(filename, "%03i.jpg", i);
                // open new file  to write to new JPG
                img = fopen(filename, "w");
                // write data to new JPG
                fwrite(x, 512, 1, img);
            }
            // increment file counter
            i++;
        }
        // if chunk of data is not start of a JPG
        else
        {
            // if file to write has been previously opened
            if (img != NULL)
            {
                // write data to previously opened file
                fwrite(x, 512, 1, img);
            }
        }
    }
    //close card file
    fclose(ptrr);
    //free allocated memory for filename
    free(filename);
}
