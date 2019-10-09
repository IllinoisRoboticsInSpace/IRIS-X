#include <stdlib.h>
#include <stdio.h>

#include "bmpGen.h"

#define WIDTH 480
#define HEIGHT 640
//#define WIDTH 4
//#define HEIGHT 3

int main() {

    // Data will be stored in significant y method
    int *data = malloc(sizeof(int) * WIDTH * HEIGHT);

    // Open file ./output
    FILE *f = fopen("./output", "r");

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            fscanf(f, "%d", &data[WIDTH * y + x]);        
        }
    }
// Test loop to make sure the data is stored correctly
/*
    for (int j = 0; j < WIDTH; j++) {
        for (int i = 0; i < HEIGHT; i++) {
            printf("%d ", data[WIDTH * i + j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    int max = 0;
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int element = data[WIDTH * y + x];
            if (element > max) {
                max = element;
            }
        }
    }
    printf("%d\n", max);

    //BMP creation in this loop
    char *bmpinput = malloc(sizeof(char) * HEIGHT * WIDTH * 3);
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int element = data[WIDTH * y + x];
            char depth = (element * 255) / max; // Normalize it between 0 and 255 

            bmpinput[3 * (WIDTH * y + x) + 0] = (char) (depth); //R
            bmpinput[3 * (WIDTH * y + x) + 1] = (char) (depth); //G
            bmpinput[3 * (WIDTH * y + x) + 2] = (char) (depth); //B
        }
    }
    generateBitmapImage(bmpinput, HEIGHT, WIDTH, "output.bmp");
    free(data);
}
