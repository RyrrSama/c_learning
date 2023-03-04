#include<stdio.h>

// extern keyword is used to define a varaible or function 
// when varaible is define the memory wont be allocated to it 
// Memory will be allocated only when the varaible is declared.
// extern will extend the visiblity of the function or varaible though out the program even to multiple files.
// So when we use extern keyword for a varible we should decalre it to allocate the space for the varaible if the varaible isnt declared any where else.
// A varaible can be decalarted many time in our code.but only once define in file function or block.
/*
extern modifier:
    It is used to re-use the varaible thta is declared in other files.
When we use extern the the varaible is only declared not defined
    which means memory is not allocated to it .
When we declare a auto varaible it is decalred and defined 
    which means memory is allocated to it.
The complier will belives whatever the extern says and complies sucefully
    but linker will throw error if the varaible inst defined anywhere in program scope
Note:
    extern will requster complier to look for definition else where and dont allocate new mwmory to it 
        To allocate memory extern varible we must inintizte value for the varaible.
    We can decalre varaibel n number of time in our c but cant define a varaible more than one time.
    When we defined a varaible in our extern declartion linker will assign value for it from other 
        initization if not allocate it to our extern defined value. 
    */ 

extern int a;
int main(){ 
    printf("%d",a);
    return 0;
}