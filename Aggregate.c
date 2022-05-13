#include <stdio.h>
#include "Aggregate.h"

float min(float *a, int size){

    if (size >= 0) {

        float min = a[0];
        for(int i = 0; i < size; i++){
            if (a[i] < min){
                min = a[i];
            }
        }
        return min;

    } else {
        printf("FATAL ERROR at line %d\n", ((__LINE__)-9));
    }
}

float max(float *a, int size){

    if (size >= 0) {

        float max = a[0];
        for(int i = 0; i < size; i++){
            if (a[i] > max){
                max = a[i];
            }
        }
        return max;

    } else {
        printf("FATAL ERROR at line %d\n", ((__LINE__)-9));
    }

    
}

float sum(float *a, int size){

    if (size >= 0) {

        float sum;
        for(int i = 0; i < size; i++){
            sum = sum + a[i];
        }
        return sum;

    } else {
        printf("FATAL ERROR at line %d\n", ((__LINE__)-5));
    }

}

float avg(float *a, int size){

    if (size >= 0) {

        float avg = sum(a, size)/size;
        return avg;

    } else {
        printf("FATAL ERROR at line %d\n", ((__LINE__)-4));
    }

}

float pseudo_avg(float *a, int size){

    if (size >= 0) {

        float value = (min(a, size)+max(a, size))/2;
        return value;

    } else {
        printf("FATAL ERROR at line %d\n", ((__LINE__)-4));
    }

}
