#include<stdio.h>
#include<string.h>
/* Union :
    * A union is a special data type available in C that allows to store 
    different data types in the same memory location.

    * You can define a union with many members, 
    but only one member can contain a value at any given time.

    * Unions provide an efficient way of using the same memory location 
    for multiple-purpose.

    * The memory occupied by a union will be large
    enough to hold the largest member of the union.
    
    NOTE:
        Last edited value will be occupied the memory locatione hence other 
        Value cant be accessed or stored. only one at a time.
*/
union {
    int age;
    char name[15];
    unsigned int height;
}user_data;

int main(){

    user_data.age = 26;
    printf("User age is : %d\n",user_data.age);
    strcpy(user_data.name, "Ramkumar.E");
    printf("User age is : %s\n",user_data.name);
    // Age will be erased because name is overwritten in the memory location.
    printf("User age is : %d\n",user_data.age);
}