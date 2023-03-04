#include<stdio.h>
    /* auto is a storage_class for all local varible
    they can be defined inside a function or block
    auto will be default added by complier while compliing no need
    to add them while defining local varaible

    Local varaible life span ends end of the function and start once function 
    calls*/

    // int local= 24; both local varible are same

    /* register storage class this is used for loacl varible 
    which need to stored in register instead of RAM
    This means varaible can have maximum size equal to register
    size (usually one word)(usally 4). This varaible cant able to have 
    memory address for them because they are saved in register instead of RAM
    So this varible we cant able to use uinary oprator '&'.
    
    Note :
    The register should only be used for variables
    that require quick access such as counters
    It should also be noted that defining 'register' does not mean that the variable 
    will be stored in a register. It means that it MIGHT be stored in a 
    register depending on hardware and implementation restrictions.
    */

    /* Static Storage Class:
    The static storage class instructs the compiler to keep a local variable
    in existence during the life-time of the program instead of creating and destroying
    it each time it comes into and goes out of scope.
    
    Important :
    Therefore, making local variables static allows them to maintain their values
    between function calls.

    The static modifier may also be applied to global variables. 
    When this is done, it causes that variable's
    scope to be restricted to the file in which it is declared.

    In C programming, when static is used on a global variable, 
    it causes only one copy of that member to be shared by all the objects of its class.*/

    /* Extern Storage Class:
    The extern storage class is used to give a reference of a global variable 
    that is visible to ALL the program files.

    When you use 'extern', the variable cannot be initialized however, it points 
    the variable name at a storage location that has been previously defined.

    When you have multiple files and you define a global variable or function,
    Which will also be used in other files, then extern will be used in another file 
    to provide the reference of defined variable or function.

    Just for understanding, extern is used to declare a global variable
    or function in another file.

    Note:
    The extern modifier is most commonly used when there are two or more files 
    sharing the same global variables or functions.
    */
void counter_function(void);
static int calls = 5;

int main(){

    auto int local = 24;// int local = 24  both are same
    register float miles= 10;// stored in register for quick access
    printf("Size of register Variable : %d \n",sizeof(miles));//usally one word (4 byte)
    // '&miles' throws error  register are not stored in RAM to have memory.
    while(calls--)
    counter_function();
}

void counter_function(void){
    static int count= 0;
    count++;
    printf("local static %d and function calls %d\n", count, calls);
}