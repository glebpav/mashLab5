#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "stdlib.h"
#include "getopt.h"
#include "fileOperator.h"


int main(int argc, char **argv) {


    // input params
    int algorithm;
    int field;
    int direction;
    char *inputDir;
    char *outputDir;
    // --------------

    int opt;

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
            inputDir = argv[optind];
        } else if (optind == 8) {
            outputDir = argv[optind];
        }
    }

    readArray(inputDir);

    return 0;
}
