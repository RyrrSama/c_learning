#include<stdio.h>

int get_total_memory(int array[],int size);
void print_2by2_matrix();
// Here function return type is a int pointer.
// C dont return a full array as function return type.
// So we can only return pointer to the array by array name.
/* Note :
    C does not advocate to return the address of a local variable to outside
    of the function, so you would have to define the local variable as static variable.
    */
   
int *get_tables(int multipler);

// int find_average(int *array);
// int find_average(int array[size]);
// int find_average(int array[]);
// all three ways are correct

int find_average(int array[], int size);

int main(void){

    //double balance[10];
    double reading[] = {0.0,11.2,34.4,56.0};
    //printf("%f", reading[3]);
    //print_2by2_matrix();
    //int mark_list[] = {1,2,3,4,5,6};
    // find_average(mark_list, 6);
    // Here return is not a full array so we are creating pointer
    // We should not create a array varibel to store a array function return type
    //int *multiper_table = get_tables(4);
    //for (int index=0; index<10;index++){
    //    printf("%d\n", multiper_table[index]);
    //}
    double *p;
    // Assigning the array address to double pointer. 
    p=reading;
    puts("Array values are listed below :");
    for (int index=0; index <5;index++){
        printf("Address of %d element = %p and value stored in %f\n",index, p+index, *(p+index) );
    }

    }

void print_2by2_matrix(){
    int a[2][2];
    for (int row=0; row<2;row++){
        for(int column=0; column<2;column++){
            a[row][column] = row+column;
            printf("The Row of %d and column of %d is : %d\n",row, column, a[row][column]);
        }
    }
}

int get_total_memory(int array[],int size)
{
    // We cant use sizeof for array like other data types.
    // The array varaible return first address of the starting element 
    // of the array.
    // So it will retrun the size of first elment in of list 
    // So we need to give the size of list in order to check 
    // The total array size.

    // formale to calutate tyotal memory to store the array:
    //
    //      sizeof(datatype)*lenght_the_array

    // printf("Size of given array : %d",sizeof(array));
    return sizeof(int)*size;
}

int find_average(int array[], int size){
    int sum = 0;
    for (int index=0; index<size; index++){
        sum+=array[index];
    }
    return (sum/size);
}

int *get_tables(int multipler){
    // Static varaibel to return memory data outside function
    // Local memeory will be destored once it went out of scope.
    static int multipler_array[10];
    for(int index=0; index<10; index++){
        multipler_array[index] = index * multipler;
    }
    return multipler_array;
}