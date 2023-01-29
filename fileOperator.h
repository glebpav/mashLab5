#ifndef MASHLAB5_FILEOPERATOR_H
#define MASHLAB5_FILEOPERATOR_H

#include <stdlib.h>

typedef struct Data {
    char idx[8];
    char *name;
    int count;
}Data;

Data readArray(char *dirToFile);

#endif //MASHLAB5_FILEOPERATOR_H
