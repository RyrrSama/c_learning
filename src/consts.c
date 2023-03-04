#include<stdio.h>
// There are two ways to define constant.
// #define preprocess
// const key word

// Data defined by the #define macro definition are preprocessed,
// so that your entire code can use it.
// This can free up space and increase compilation times.
// where as #DEFINEs are handled by the pre-processor.
// It is faster than const
// It can be changed in complie time with -d flag 
// By using -d flag we can redefine it 
// it replace like regrex
// cant able to do type checking.
#define AREA 3.5

// CONSTs are handled by the compiler,
// The big advantage of const over #define is type checking
// It cant be changed 
// We cant able to change values using pointers but so complier will allow it 
// But its not good thing to do 
const int VOLUME = 34;

int main(){
    // puts and printf can only print consts char only 
    // To print varaibles we need to do it in printf by format string
    printf("%d", VOLUME);
}