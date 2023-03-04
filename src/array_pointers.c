#include<stdio.h>

int main(void){
    
    int numbers[] = {1,2,3,4,5,6,7,8,9,0};
    int *number_ptr[10];

    for(int index=0;index<=9;index++){
        number_ptr[index]=&numbers[index];
    }

    for(int index=0;index<=9;index++){
        printf("Value at number_ptr[%d] is %d \n",index,*number_ptr[index]);
    }
    // This is char pointer which can hold a string in it. 
    // we can access each char by using index in char* pointer.
    char *name = "Ramkumare.E";
    // This is char array which holds a single char in  each index.
    // We can access each value at each index
    // %c for char and %s for string
    char names[] = "Ramkumare.E";
    printf("%c\n",name[3]);
    // This is array of string in single list we can access each name in single index.
    // And we can access each char in our string  by double indexing like multi dimension array
    char *name_list[5]={"Ram", "kumar","arun","kumar","manisha"};
    printf("%s\n",name_list[3]);
    printf("%c\n",name_list[3][1]);

}