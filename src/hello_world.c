// Inbuild header which have declaration of printf
// stdio -> Standed Input/out
// PreProcessing Dirtective:
    // #include is the preprocessing diretory
    // which runs before compliation of the code starts.
    // This is will include the src code of the included header file to the code
#include<stdio.h>

// This is main function
//  main() is the entry for all program.
// every program should have main function declaration.
// int is return type of main function. WHich indicate the failure/Success of the program.
// void Parameter represent no parameter for a fuction.
int main(void){

    // printf declared in stdio.h header inbuild header.
    // parameter should be char * type
    // Printf given string in console.
    // \n is the escape charater used for newline.
    printf("Hello World\n");

    // return exit code of the program.
    // zero indicate success of the program . non zero indicate failture of the program.
    return 0;

}
