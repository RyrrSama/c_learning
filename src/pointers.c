#include<stdio.h>

int main(void){

    int age;
    // Declaration of int pointer 
    int *age_pointer;
    // Getting the address of age and storing 
    age_pointer = &age;
    // %x or %p can be used to print the address of the varaible
    printf("Address for varaible 'age' is : %x\n",&age);
    printf("Address of 'age_pointer' is : %x\n",&age_pointer);
    // DeReference the pointer varaible to get value holds on the address is by * symbol on pinters.
    printf("Address for varaible 'age_pointer' is : %d\n",*age_pointer);

    /* NUll Pointer:
    It is always a good practice to assign a NULL value to a pointer variable
    in case you do not have an exact address to be assigned.

    This is done at the time of variable declaration. 
    A pointer that is assigned NULL is called a null pointer.

    The NULL pointer is a constant with a value of zero
    defined in several standard libraries.

    In most of the operating systems, programs are not permitted to access memory at address 0 
    because that memory is reserved by the operating system.

    the memory address 0 has special significance; 
    It signals that the pointer is not intended to point to an accessible memory location.
    int *null_pointer = NULL;
    By convention, if a pointer contains the null (zero) value, it is assumed to point to nothing.
    */
   int *null_pointer = NULL;
   if (null_pointer){
    printf("Given pointer is not Null");
   }
   else{
    printf("Given pointer is a Null Pointer");
   }
    return 0;
}