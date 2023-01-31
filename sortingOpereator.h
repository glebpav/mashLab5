#include "fileOperator.h"

#ifndef MASHLAB5_SORTINGOPEREATOR_H
#define MASHLAB5_SORTINGOPEREATOR_H

double sortArray(Data **array, int arraySize, int direction, int algorithm, int field);

int stringsComparator(char *a, char *b);

int comparatorName1(const void *a, const void *b);
int comparatorName2(const void *a, const void *b);
int comparatorIdx1(const void *a, const void *b);
int comparatorIdx2(const void *a, const void *b);
int comparatorCount1(const void *a, const void *b);
int comparatorCount2(const void *a, const void *b);

#endif //MASHLAB5_SORTINGOPEREATOR_H
