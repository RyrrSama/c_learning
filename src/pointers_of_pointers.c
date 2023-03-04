#include<stdio.h>

int main(){
    int age =12;
    int *pointer_age = &age;
    // To define pointer to pointer  we need to define it with **var_name;
    // the outer most * denoted a pointer varaible  the inner * denotes the varaible type 
    // which means it gonna a hold pointer data type address in it.
    // we can derefernce the reference by using ** for a pointer to pointer.
    int **pointer_to_pointer = &pointer_age;
    printf("Value of age : %d\n",age);
    printf("Value of pointer_age : %d\n",*pointer_age);
    printf("Value of pointer_to_pointer : %d\n",**pointer_to_pointer);
}