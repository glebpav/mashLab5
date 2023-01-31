#ifndef MASHLAB5_FILEOPERATOR_H
#define MASHLAB5_FILEOPERATOR_H

#include <stdlib.h>

typedef struct Data {
    char idx[9];
    char *name;
    int count;
}Data;

Data *readArray(char *dirToFile, int *arraySize);
void writeArray(Data *dataArray, int dataArrayLen, char *outputDir);

#endif //MASHLAB5_FILEOPERATOR_H
