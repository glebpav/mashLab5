#include <stdio.h>
#include "fileOperator.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

Data *readArray(char *dirToFile, int *arraySize) {
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

    Data *dataArray = NULL;

    *arraySize = 0;
    char **linesArray = NULL;
    int linesArraySize = 0;

    char *subData = strtok(wordsArray, ";");
    while (subData != NULL) {
        if (0 != strcmp(subData, " ")) {
            linesArray = realloc(linesArray, (1 + linesArraySize) * sizeof(char *));
            linesArray[linesArraySize] = strdup(subData);
            linesArraySize += 1;
        }
        subData = strtok(NULL, ";");
    }
    //printf();
    for (int lineIdx = 0; lineIdx < linesArraySize; lineIdx++) {

        Data dataItem;
        char uid[9];
        char *name;
        int count;
        char *subField = strtok(linesArray[lineIdx], ",");

        for (int i = 0; i < 3; i++) {

            printf("subfield \"%s\"\n", subField);

            if (subField == NULL) {
                printf("Error5");
                exit(-1);
            }
            switch (i) {
                case 0:
                    while (subField[0] == ' ') {
                        for (int z = 0; z < strlen(subField); z++)
                            subField[z] = subField[z + 1];
                    }

                    if (strlen(subField) != 8) {
                        printf("error: \"%s\"\n", subField);
                        printf("Error6");
                        exit(-1);
                    }
                    for (int q = 0; q < 8; q++)uid[q] = subField[q];
                    break;
                case 1:
                    name = (subField);
                    break;
                case 2:
                    count = atoi(subField);
                    break;
            }
            subField = strtok(NULL, ",");
        }
        uid[8] = '\0';
        printf("NOT FROM CASE 1 subfield \"%s\"\n", name);
        /*dataItem.name = calloc(strlen(name) + 1, sizeof(char));
        dataItem.name = name;
        for (int q = 0; q < 9; q++) dataItem.idx[q] = uid[q];
        dataItem.count = count;*/

        dataArray = realloc(dataArray, (*arraySize + 1) * sizeof(Data));
        dataArray[*arraySize].name = strdup(name);
        for (int q = 0; q < 9; q++) dataArray[*arraySize].idx[q] = uid[q];
        dataArray[*arraySize].count = count;
        *arraySize += 1;
    }


    printf("count of el: %d\n", *arraySize);
    for (int i = 0; i < *arraySize; i++) {
        printf("uid: %s\n", dataArray[i].idx);
        printf("name: %s\n", dataArray[i].name);
        printf("count: %d\n\n", dataArray[i].count);
    }

    for (int i = 0; i < linesArraySize; ++i) {
        free(linesArray[i]);
    }
    free(linesArray);
    free(wordsArray);

    return dataArray;
}

void writeArray(Data *dataArray, int dataArrayLen, char *outputDir) {
    FILE *f;


    if ((f = fopen(outputDir, "w")) == NULL) {
        printf("Error\n");
        exit(1);
    }

    for (int i = 0; i < dataArrayLen; i++)
        fprintf(f, "%s, %s, %d;\n", dataArray[i].idx, dataArray[i].name, dataArray[i].count);

    fclose(f);
}