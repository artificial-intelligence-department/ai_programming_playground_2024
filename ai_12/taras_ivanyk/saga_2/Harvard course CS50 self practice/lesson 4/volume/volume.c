#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    if (argc != 4){
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL){
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL){
        printf("Could not open output file.\n");
        fclose(input);
        return 1;
    }

    float factor = atof(argv[3]);

    typedef uint8_t BYTE;
    BYTE header[HEADER_SIZE];

    if (fread(header, HEADER_SIZE, 1, input) != 1)
    {
        printf("Error reading header from input file.\n");
        fclose(input);
        fclose(output);
        return 1;
    }
    fwrite(header, HEADER_SIZE, 1, output);

    // Process the audio data (16-bit samples)
    int16_t buffer;

    while (fread(&buffer, sizeof(int16_t), 1, input) == 1){
        buffer = (int16_t)(buffer * factor);
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    fclose(input);
    fclose(output);

    return 0;
}

/*    volume.c compilates in GitBash, using commands:
   
   gcc volume.c -o volume.exe      [to compilate .c with .exe]

then:   ./volume.exe input.wav output.wav 3.0  

(0.5 - just for example, you can write factor what you want to)    */