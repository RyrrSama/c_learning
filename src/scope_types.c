#include<stdio.h>
// Global varable:
char username[] = "HelloWorld";
/* 
Here age is formal Parameter it is simular to local
local varaible.
*/
void print_age(int age);

/*
Simiarly formal parameter will take precedence insidea function 
then a global varaible
*/
void print_username(char username[]);

/*
Note:

*When a local variable is defined, it is not initialized by the system, 
you must initialize it yourself. 

*Global variables are initialized automatically 
by the system when you define them as follows.

int -> 0
char -> '\0'
double -> 0
float -> 0
pointer -> NULL
*/

int main(void){
    // local varaible
    int a =10;
    /* Local varible and Global varaible can have same name 
    local varaible will take precedence than global varaible inside
    block or functions.
    */
   char username[] = "Ramkumar";
   printf("Local varaible takens precedence inside function: ");
   puts(username);
   // Here formal parameter will print due to precedence
   print_username("Ramkumar.E");
}

void print_age(int age){
    printf("Given age is : %d", age);
}

void print_username(char username[]){
    printf("The given username : ");
    puts(username);
}