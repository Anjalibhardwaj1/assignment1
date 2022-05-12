#include <stdio.h>
#include "Aggregate.h"
#include "Aggregate.c"

int main() {

    //float (*aggregates[5])(float*, int) = {&min, &max, &sum, &avg, &pseudo_avg};

    float arr1[5] = {4.6, 2.2, 8.7, 4.3, 11.5};

    printf("%f\n", pseudo_avg(arr1, -1));

    //float arr1[5] = {4.6, 2.2, 8.7, 4.3, 11.5};
    //float arr2[10] = {0.2, 5.3, 8.9, 1.6, 8.2, 5.0, 1.2, 4.6, 2.3, 9.4};

    //for (int i = 0; i < 5; i++) {

        //printf("%f\n", (*(aggregates[i]))(arr1, 5));
        //printf("%f\n", (*(aggregates[i]))(arr2, 10));

    //}

    return 0;

}