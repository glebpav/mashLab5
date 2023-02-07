#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stdbool.h"
#include "stdlib.h"
#include "getopt.h"
#include "fileOperator.h"
#include "sortingOpereator.h"


char *generateStr(int len) {
    const char alphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNMabcdefghijklmnopqrstuvwxyz";
    char *str = calloc(len, sizeof(len));
    for (int i = 0; i < len; i++) str[i] = alphabet[rand() % (int) (sizeof alphabet - 1)];
    return str;
}

char generateChar() {
    const char alphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNMabcdefghijklmnopqrstuvwxyz";
    return alphabet[rand() % (int) (sizeof alphabet - 1)];
}


int main(int argc, char **argv) {

    // input params

    int algorithm;      // 0 - qsort, 1 - gnome, 2 - pair
    int field;          // 0 - uid,   2 - name,  2 - count
    int direction;      // 0 - from big to small, 1 - from small to big
    int numOfElements;
    int numOfArray;

    // --------------

    int opt;
    double fullTime, begin, end;

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
    for (; optind < argc; optind++) {
        if (optind == 7) {
            numOfElements = atoi(argv[optind]);
        } else if (optind == 8) {
            numOfArray = atoi(argv[optind]);
        }
    }

    for (int arrayIdx = 0; arrayIdx < numOfArray; ++arrayIdx) {

        Data *dataArray = calloc(numOfElements, sizeof(Data));
        for (int i = 0; i < numOfElements; i++) {
            dataArray[i].count = (rand() * 1000) % 1000;
            dataArray[i].name = generateStr(16);
            for (int j = 0; j < 8; ++j) dataArray[i].idx[j] = generateChar();
        }

        begin = clock();
        sortArray(&dataArray, numOfElements, direction, algorithm, field);
        end = clock();
        for (int i = 0; i < numOfElements; ++i) free(dataArray[i].name);
        free(dataArray);
        fullTime += end - begin;

    }

    printf("avg time of sorting: %f\n", fullTime / numOfArray / CLOCKS_PER_SEC);
    return 0;
}