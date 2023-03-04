#include<stdio.h>
/*
Each identifier that appears in a C program is visible (that is, may be used) only in some possibly discontiguous portion of the source code called its scope.
Within a scope, an identifier may designate more than one entity only if the entities are in different name spaces.

C has four kinds of scopes:

1.block scope
2.file scope
3.function scope
4.function prototype scope
*/
// storage about File-scope 
//      identifiers have external linkage and static storage duration by default.

// Storage about Block scope
/*      Block-scope variables have no linkage and automatic storage duration by default.
Note that storage duration for non-VLA local variables begins when the block is entered,
but until the declaration is seen, the variable is not in scope and cannot be accessed.*/

char* userName = "Outter Varaible";// file scope starts here 

void printUserName(void){
    // Outer Block scope starts here hides file scope.
    // Block is used for all Block like(functions, if, else, while,e.t.c).
    // Block scope ends at block end '}'.
    char* userName = "Ramkumar.E";
    {
        char* userName = "Inner Varaible";// Inner block scope starts here hides outter block and other block
        puts(userName);// prints inner block varaible
    }    
    puts(userName);// print outter block varible
}
// Function scope:
//      The scope of a name introduced in the parameter list of a function declaration 
// that is not a definition ends at the end of the function declarator.

void getUserName(int userName); // Here we used function prototype scope

int main(void){

    puts(userName); // Prints file scope varaible.
    printUserName();

}

