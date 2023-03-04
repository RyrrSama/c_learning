#include<stdio.h>
void print_module_5(int start, int end);

void print_module_5(int start, int end){
    MOD5:
        printf("Number is div by 5\n");

    for (int num=start; num<=end; num++ ){
        if (num%5==0){
            num++;
            goto MOD5;
        }
        printf("%d num not div by 5\n", num);
    }
}
int main () {

   /* local variable definition */
   int a = 10;

   /* do loop execution */
   LOOP:do {
   
      if( a == 15) {
         /* skip the iteration */
         a++;
         goto LOOP;
      }
		
      printf("value of a: %d\n", a);
      a++;

   }while( a < 20 );

   print_module_5(5,10);
 
   return 0;
}