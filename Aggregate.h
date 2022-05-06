//Functions and Pointers

#include <stdio.h>

float min(float a[]){
    float min = a[0];
    for(int i = 0; i < sizeof(a); i++){
        if (a[i] < min){
            min = a[i];
        }
    }
    return min;
}

float max(float a[]){
    float max = a[0];
    for(int i = 0; i < sizeof(a); i++){
        if (a[i] > max){
            max = a[i];
        }
    }
    return max;
}

float sum(float a[]){
    float sum;
    for(int i = 0; i < sizeof(a); i++){
        sum = sum + a[i];
    }
    return sum;
}

float avg(float a[], float sum){
    float avg = sum/sizeof(a);
    return avg;
}

float pseudo_avg(float a[], float min, float max){
    float value = (min+max)/2;
    return value;
}


//q4
//define an array of pointer functions called aggregates
//contain 5 pointers to the 5 functions
//float (*aggregates[5]) (float) = {&min, &max, &sum, &avg, &pseudo_avg};


//write a short for loop that iterates through an array of functions and calls each function on the two sample arrays you defined. the loop prints the calculated values in 10 
//separate lines. 

