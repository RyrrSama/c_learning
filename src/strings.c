#include<stdio.h>

int main(){
    // There is no String datatype in c 
    // Char arrays is used as a string in c 
    // This is sequence of character

    /* NOTE:
    Strings are actually one-dimensional array 
    of characters terminated by a null character '\0'.

    Thus a null-terminated string contains the characters that comprise 
    The string followed by a null.

    The following declaration and initialization create a string consisting 
    of the word "Hello". 

    To hold the null character at the end of the array, 
    the size of the character array containing the string is one more 
    than the number of characters in the word "Hello."

    You do not place the null character at the end of a string constant. 
    The C compiler automatically places the '\0' at the end of the string 
    when it initializes the array. 
    */
    // By using array name it uses the char* pointer to read staring value till it reaches
    // Null terminator to end the string
    char name[] ="Ramkumar.E";
    printf("The name of the user is : %s\n",name);
    return 0;
}