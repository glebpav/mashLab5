#include <stdio.h>
#include "fileOperator.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

Data readArray(char *dirToFile) {
    FILE *fp;

    if ((fp = fopen(dirToFile, "r+")) == NULL) {
        printf("Error4");
        exit(0);
    }

    char *item = malloc(80 * sizeof(char));
    int check = fscanf(fp, "%s ", item);
    char *wordsArray = calloc(10000, sizeof(char));

    while (check != EOF) {
        if (check == 1) {
            wordsArray = strcat(wordsArray, item);
            wordsArray = strcat(wordsArray, " ");
        }
        check = fscanf(fp, "%s ", item);
    }

    fclose(fp);
    printf("%s\n", wordsArray);
    free(item);

    Data *dataArray;

    int arraySize = 0;
    printf("here\n");
    char *subData = strtok(wordsArray, ";");
    while (subData != NULL) {

        Data dataItem;
        char uid[8];
        char *name;
        int count;
        char *subField = strtok(NULL, ",");

        for (int i = 0; i < 3; i++) {
            if (subField == NULL) {
                printf("Error");
                exit(-1);
            }
            switch (i) {
                case 0:
                    if (strlen(uid) != 8) {
                        printf("Error");
                        exit(-1);
                    }
                    for (int q = 0; q < 8; q++)uid[q] = subField[q];
                    break;
                case 1:
                    name = strdup(subField);
                    break;
                case 2:
                    count = atoi(subField);
                    break;
            }
            subField = strtok(NULL, ",");
        }

        dataItem.name = name;
        for (int q = 0; q < 8; q++) dataItem.idx[q] = uid[q];
        dataItem.count = count;

        dataArray = realloc(dataArray, arraySize + 1);
        dataArray[arraySize] = dataItem;
        arraySize += 1;

        subData = strtok(NULL, ";");
    }

    printf("count of el: %d\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("uid: %s\n", dataArray[i].idx);
        printf("name: %s\n", dataArray[i].name);
        printf("count: %d\n\n", dataArray[i].count);
    }

}