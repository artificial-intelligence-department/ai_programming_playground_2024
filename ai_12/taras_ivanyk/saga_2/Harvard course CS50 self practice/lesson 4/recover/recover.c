#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    if(!card){
        printf("Error, file wasn't opened!\n");
        return 2;
    }

    uint8_t buffer[512];
    FILE *img = NULL;
    int img_count = 1;

    while(fread(buffer, 1, 512, card) == 512){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef){
            if(img != NULL){
                fclose(img);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", img_count);
            img = fopen(filename, "w");
            if(img == NULL){
                printf("Error, couldn't create %s\n", filename);
                fclose(card);
                return 3;
            }
            img_count++;
        }
        if(img != NULL){
            fwrite(buffer, 1, 512, img);
        }
    }
    if(img != NULL){
        fclose(img);
    }
    fclose(card);

    return 0;
}
