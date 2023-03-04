/*The <stdio.h> header provides generic file operation support and supplies functions
with narrow character input/output capabilities.*/ 
#include<stdio.h>
// main() where function excetution
int main(void){
    // outputs char strings to output steam without '/n' at the end by default
    printf("hello world:");
    //puts() used to put char string in output stream with '/n' at the end of the string
    puts("Printable cChar:");
    // pre increment ++Variable: increment happens same line.
    // post increment Variable++: increment happens from next line.
    // All printable char starts from 32 to 127 ASCCI code.
    for(int chr =32; chr<127; ++chr){
        // putchar() is used to convert ASCCI char to output stream before displaying
        putchar(chr);
        // Here we used ternary operator (condition) ? True block : False block
        putchar(chr % 16 == 15 ? '\n' : ' ');

    }
}