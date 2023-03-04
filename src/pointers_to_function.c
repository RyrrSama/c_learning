#include<stdio.h>
void change_age(unsigned int * age, unsigned int value);

int main(){
    unsigned int age =24;
    change_age(&age, 46);
    printf("Student age : %d\n",age);
}

void change_age(unsigned int *age, unsigned int value){
    *age =value;
}