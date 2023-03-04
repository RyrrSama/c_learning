#include<stdio.h>
// float.h is have macros defined in them for limts for float data types.
// like (FLT_Max,FLT_MIN, e.t.c)
#include<float.h>

int main(){
    // Floating data do not have signed and unsigned .
    // They dont work combine with signed and unsigned keyword.
    // float data type used to store float decimal values.
    // It takes 4 bytes to store a floating value in our computer.
    // It can store 6 decimal places 
    float user_height = 5.5;

    // It takes 8 bytes to store a double value in our computer.
    // It can store 15 decimal points.
    double distance_travelled_light = 572348.34234234;

    // long double can store up to 19 decimals.
    // It takes 10 bytes to store a long doubles value .
    long double size_of_neluba = 6234234234545.345352342342342;
}