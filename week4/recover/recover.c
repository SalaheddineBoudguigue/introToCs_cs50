// To recover deleted images from a camera

#include <stdio.h>
#include <stdlib.h> // to manage memory (in this case using malloc)
#include <stdint.h> // uint8
#include <stdbool.h> // to define boolean function


typedef uint8_t BYTE;

bool isJpeg(BYTE buffer[512]); // To check the block signature whether it
                               // corresponds to one of a Jpeg

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./recover FileToRecover.raw\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Input file couldn't open\n");
        return 1;
    }

    int block_size = 512;


    BYTE buffer[512];
    int i = 0;
    char *picture = malloc(8*sizeof(char));
    FILE *ptrIm = NULL;

    while (fread(buffer, sizeof(BYTE), block_size, input) != 0)
    {
        if (isJpeg(buffer))
        {
            // we open a new jpeg file in w mode to write the jpeg blocks
            // as long as that block doesn t start with a new signature
            sprintf(picture, "%03i.jpg", i);

            ptrIm = fopen(picture, "w");
            i++;
        }
        if (ptrIm != NULL)
        {
            fwrite(buffer, sizeof(BYTE), block_size, ptrIm);
        }
    }
    fclose(input);
    fclose(ptrIm);
    free(picture);

}


bool isJpeg(BYTE buffer[512])
{
    if (buffer[0]== 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}