#include<stdio.h>
// string header file holds in build string function in it.
#include<string.h>

int main(){

    char src1[15] = {'H','E','L','L','O'};
    char src2[] = "WORD";
    char src3[] = "welcome";
    // Copy the string stc3 to src1 by value.
    // Syntax : strcpy(des,src)
    // destination should be big enough to hold the src values len(des)>len(src)
    // Address of given varaible wont be changed values in address will be over written.
    printf("%x\n",src3);
    printf("%x\n",src1);
    strcpy(src3,src1);
    printf("%x\n",src3);
    printf("%x\n",src1);
    // Concat both string together s2 on the end src1
    // The src should big enought to hold both values in the varaible.
    // Syntax : strcat(des,src) ->dessrc
    // It Replace value in src1 by appending it.
    // It returns Nothing.
    strcat(src1,src2);
    printf("%s\n",src1);
    // strlen() is used to return the length of the given string.
    // It Returns the length of the string not not the declarted array length.
    int length_str = strlen(src1);
    printf("%s -> %d",src1,length_str);
    return 0;

}