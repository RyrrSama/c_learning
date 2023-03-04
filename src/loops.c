#include<stdio.h>
/* 
Do while loops while block wont be having block 
Do while loop used to excute atleast once in our code.

syntax:
    do{}
    while(condition);
*/

static int a =100;

void while_loop(void);
void do_while_loop(void);
void for_loop(void);
void infinity_loop(void);

int main(){
    while_loop();
    for_loop();
    do_while_loop();
    infinity_loop();
}

void while_loop(void){
    
    while(a>90){
        a--;
        printf("Value of a in while loop: %d\n", a);
    }
}

void for_loop(void){
    for(a; a>50;a--){
        printf("Value of a in for loop: %d\n", a);
    }
}

void do_while_loop(void){
    do{
        printf("value of a in do while loop: %d\n", a);
        a--;
    }
    while(a>10);
}

void infinity_loop(void){
    for(;;){
        if (a){
            printf("Value of a in for infinite loop: %d\n", a);
            a--;
        }
        else{
            break;
        }
    }
}