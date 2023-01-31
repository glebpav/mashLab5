#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "sortingOpereator.h"

void swap(void *item1, void *item2, size_t sizeOfOneElement) {
    char temp[sizeOfOneElement];
    memcpy(temp, item2, sizeof(Data));
    memcpy(item2, item1, sizeof(Data));
    memcpy(item1, temp, sizeof(Data));
}

void gnome(void *array, int size, size_t sizeOfOneElement, int (*ptFuncCompare)(const void *, const void *)) {
    int index = 0;

    while (index < size) {
        if (index == 0) index++;
        if (0 < ptFuncCompare((array + index * sizeOfOneElement), (array + sizeOfOneElement * (index - 1)))) index++;
        else {
            swap((array + index * sizeOfOneElement), (array + sizeOfOneElement * (index - 1)), sizeOfOneElement);
            index--;
        }
    }
}

void pair(void *array, int size, size_t sizeOfOneElement, int (*ptFuncCompare)(const void *, const void *)) {
    for (int i = 1; i < size; i++) {
        for (int j = i;
             j > 0 && ptFuncCompare((array + j * sizeOfOneElement), (array + sizeOfOneElement * (j - 1))) < 0; j--) {
            swap((array + j * sizeOfOneElement), (array + (j - 1) * sizeOfOneElement), sizeOfOneElement);
        }
    }
}

int stringsComparator(char *a, char *b) {
    while (*a != '\0' && *a == *b) {
        a++;
        b++;
    }
    return (*a - *b);
}

int comparatorName1(const void *a, const void *b) {
    const Data *item1 = a, *item2 = b;
    int c = stringsComparator(item1->name, item2->name);
    return c;
}

int comparatorName2(const void *a, const void *b) {
    const Data *item1 = a, *item2 = b;
    int c = -1 * stringsComparator(item1->name, item2->name);
    return c;
}

int comparatorIdx1(const void *a, const void *b) {
    const Data *item1 = a, *item2 = b;
    int c = 0;

    for (int i = 0; i < 8 && c == 0; i++) {
        c = item1->idx[i] - item2->idx[i];
    }
    return c;
}

int comparatorIdx2(const void *a, const void *b) {
    const Data *item1 = a, *item2 = b;
    int c = 0;

    for (int i = 0; i < 8 && c == 0; i++) {
        c = item2->idx[i] - item1->idx[i];
    }
    return c;
}

int comparatorCount1(const void *a, const void *b) {
    const Data *item1 = a, *item2 = b;
    int c = item1->count - item2->count;
    return c;
}

int comparatorCount2(const void *a, const void *b) {
    const Data *item1 = a, *item2 = b;
    int c = item2->count - item1->count;
    return c;
}

double sortArray(Data **array, int arraySize, int direction, int algorithm, int field) {

    if (field == 0 && algorithm == 0 && direction == 0)
        qsort(*array, arraySize, sizeof(Data), comparatorIdx1);
    else if (field == 0 && algorithm == 0 && direction == 1)
        qsort(*array, arraySize, sizeof(Data), comparatorIdx2);
    else if (field == 1 && algorithm == 0 && direction == 0)
        qsort(*array, arraySize, sizeof(Data), comparatorName1);
    else if (field == 1 && algorithm == 0 && direction == 1)
        qsort(*array, arraySize, sizeof(Data), comparatorName2);
    else if (field == 2 && algorithm == 0 && direction == 0)
        qsort(*array, arraySize, sizeof(Data), comparatorCount1);
    else if (field == 2 && algorithm == 0 && direction == 1)
        qsort(*array, arraySize, sizeof(Data), comparatorCount2);

    else if (field == 0 && algorithm == 1 && direction == 0)
        gnome(*array, arraySize, sizeof(Data), comparatorIdx1);
    else if (field == 0 && algorithm == 1 && direction == 1)
        gnome(*array, arraySize, sizeof(Data), comparatorIdx2);
    else if (field == 1 && algorithm == 1 && direction == 0)
        gnome(*array, arraySize, sizeof(Data), comparatorName1);
    else if (field == 1 && algorithm == 1 && direction == 1)
        gnome(*array, arraySize, sizeof(Data), comparatorName2);
    else if (field == 2 && algorithm == 1 && direction == 0)
        gnome(*array, arraySize, sizeof(Data), comparatorCount1);
    else if (field == 2 && algorithm == 1 && direction == 1)
        gnome(*array, arraySize, sizeof(Data), comparatorCount2);

    else if (field == 0 && algorithm == 2 && direction == 0)
        qsort(*array, arraySize, sizeof(Data), comparatorIdx1);
    else if (field == 0 && algorithm == 2 && direction == 1)
        qsort(*array, arraySize, sizeof(Data), comparatorIdx2);
    else if (field == 1 && algorithm == 2 && direction == 0)
        qsort(*array, arraySize, sizeof(Data), comparatorName1);
    else if (field == 1 && algorithm == 2 && direction == 1)
        qsort(*array, arraySize, sizeof(Data), comparatorName2);
    else if (field == 2 && algorithm == 2 && direction == 0)
        qsort(*array, arraySize, sizeof(Data), comparatorCount1);
    else if (field == 2 && algorithm == 2 && direction == 1)
        qsort(*array, arraySize, sizeof(Data), comparatorCount2);

}


