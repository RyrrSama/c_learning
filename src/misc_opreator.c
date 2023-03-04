#include<stdio.h>

/*
uniary & operator:

This is used to return address of an varaible.
mostly used to get address of the varaible.

uniary * opreator:

This is used to decalred a pointer varaible.
This also used to derefernce a pointer varaible to get vaule saved in the poniter.
Poniter varible can only store address.

ternary oprator:
This is a single line if statement.
syntax:
    codition ? True_block : False_block
*/

int main(){

    int a = 10;
    printf("Memory Address for a : %p\n",&a);

    int *b = &a;
    printf("Value for b : %d\n",*b);
    printf("Memory Address for b : %p\n",b);
    printf("Size for storing Adress :%d\n",sizeof(b));

    char *str = a>10 ? "High" : "Low";
    printf("Value allocated for str :%s\n",str);
}