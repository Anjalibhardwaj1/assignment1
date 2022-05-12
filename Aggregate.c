#include <stdio.h>
#include "Aggregate.h"

float min(float *a, int size){
    float min = a[0];
    for(int i = 0; i < size; i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    return min;
}

float max(float *a, int size){
    float max = a[0];
    for(int i = 0; i < size; i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

float sum(float *a, int size){
    float sum;
    for(int i = 0; i < size; i++){
        sum = sum + a[i];
    }
    return sum;
}

float avg(float *a, int size){
    float avg = sum(a, size)/size;
    return avg;
}

float pseudo_avg(float *a, int size){
    float value = (min(a, size)+max(a, size))/2;
    return value;
}

//int main()
//{

    //float arr[] = {1, 4, 5, 6.8, -1};
    //float average = avg(arr, 5);
    //printf("%f\n", average);

    //q3
    //for inputs that are null or no positive give a "fatal error" and the program is aborted. 

    //q4
    //define two arrays of float numbers that contain 5 and 10 respectively. 
    //float arr1[5] = {4.6, 2.2, 8.7, 4.3};
    //float arr2[10] = {2.4, 5.3, 8.9, 1.6, 8.2, 5.0, 1.2, 4.6, 2.3, 9.4};
//}