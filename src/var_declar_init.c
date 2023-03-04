#include<stdio.h>

int main(void){
    /* Varaible declartation:     
    Varaible declartation tells the complier where to store and
    how much space need to store the varaible in our memory.

    A variable declaration provides assurance to the compiler that there exists.
    A variable with the given type and name 
    so that the compiler can proceed for further compilation
     without requiring the complete detail about the variable

    A variable declaration is useful when you are using multiple files and 
    you define your variable in one of the files 
    which will be available at the time of linking of the program

    
    */
    int age;
    float height;
    int roll_no, emp_id;
    /* Varaible initializer :
            Varaible initializer used to assign value to declarted memory address.
    before initializer varaible must be declarted.*/

    // Note :
    //      variables with static storage duration are implicitly initialized with NULL 
    //      All bytes have the value 0; 
    //      The initial value of all other variables are undefined.
    //      the compiler needs actual variable definition at the time of linking the program
    //      A variable definition has its meaning at the time of compilation only

    age= 24 ;
    height = 5.5;
    roll_no = 114;
    emp_id = 310114106114;


}