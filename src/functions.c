#include<stdio.h>
/* function declartation:
    
    * Declaration of function used to tell complier about function
    return type , parameter list, function name e.t.c
    
    * Function declaration should be done at the begining of the file
    inorder use of function any where in our programs
    
    *Declaration should be benning of the file.
*/

int return_max_value(int fvalue, int svalue);
int add_two_number(int fvalue, int svalue);

int main(void){

    int imax = return_max_value(10,20);
    int iadd = add_two_number(4, 4);
    printf("The max value in 10 and 20 is : %d\n", imax);
    printf("The addition of 4+4 both value is : %d\n", iadd);
    return 0;

}

int return_max_value(int fvalue, int svalue){

    int result = 0; 
    if (fvalue>svalue)
        result = fvalue;
    else
        result = svalue;
    return result;

}

int add_two_number(int fvalue, int svalue){

    return (fvalue + svalue);
}