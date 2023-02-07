#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "stdlib.h"
#include "getopt.h"
#include "fileOperator.h"
#include "sortingOpereator.h"


int main(int argc, char **argv) {

    // input params

    int algorithm;      // 0 - qsort, 1 - gnome, 2 - pair
    int field;          // 0 - uid,   1 - name,  2 - count
    int direction;      // 0 - from big to small, 1 - from small to big
    char *inputDir;
    char *outputDir;

    // --------------

    int dataArraySize = 0;
    int opt;

    // чтение опций из консоли
    while ((opt = getopt(argc, argv, "d:a:v:")) != -1) {
        int inputValue = atoi(optarg);
        switch (opt) {
            case 'a':
                if (inputValue < 0 || inputValue > 2) {
                    printf("Error1");
                    exit(-1);
                }
                algorithm = inputValue;
                break;
            case 'v':
                if (inputValue < 0 || inputValue > 2) {
                    printf("Error2");
                    exit(-1);
                }
                field = inputValue;
                break;
            case 'd':
                if (inputValue < 0 || inputValue > 1) {
                    printf("Error3");
                    exit(-1);
                }
                direction = inputValue;
                break;
        }
    }

    // чтение позиционных аршгументов
    for (; optind < argc; optind++) {
        if (optind == 7) {
            inputDir = argv[optind];
        } else if (optind == 8) {
            outputDir = argv[optind];
        }
    }


    Data *dataArray = readArray(inputDir, &dataArraySize);
    sortArray(&dataArray, dataArraySize, direction, algorithm, field);

    printf("\noutput array: \n");
    for (int i = 0; i < dataArraySize; i++) {
        printf("[%d] uid: %s\n", i , dataArray[i].idx);
        printf("[%d] name: %s\n", i , dataArray[i].name);
        printf("[%d] count: %d\n\n", i , dataArray[i].count);
    }

    writeArray(dataArray, dataArraySize, outputDir);

    for (int i = 0; i < dataArraySize; ++i) {
        free(dataArray[i].name);
    }
    free(dataArray);
    return 0;
}
