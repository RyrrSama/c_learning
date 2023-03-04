#include<stdio.h>

// Void data type represent the None values or empty value.
// Void function return type represent the no value will be return from the function.

// Function declartation
// void return type represted the No value will be retured by function
// function declaration will inform a complier about the function in complie time
// and alocate the memory for it.
// Here we used void as function return type
void hello_world(void);

// Here we used void as function parameter type to define it as no parameter is accepted by function on call

void hello_world(void){

    printf("Hello World");
}

int main(){
    
    // Here we used void as a pointer data type.
    // It used to point the address of the object.
    // This can be casted to any to data type in runtime.

    void *null_pointer ;
    hello_world();

    return 0;    
}