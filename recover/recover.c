#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }
    unsigned char buffer[512];
    int ic = 0;

    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", ic);
            output_file = fopen(filename, "w");
            ic++;
        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(input_file);
    return 0;
}