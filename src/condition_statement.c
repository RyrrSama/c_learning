#include<stdio.h>
//C programming language assumes any non-zero and non-null values as true, 
//and if it is either zero or null, then it is assumed as false value.
int main(){

    int a = 10;
    
    if (a>10){
        puts("A is greater than 10");
    }
    else{
        puts("A is smaller than 10");
    }


    if (a%10==0){
        puts("A is divisble by 10");
    }
    else if(a%5==0){
        puts("A is divisble bt 5");
    }

}