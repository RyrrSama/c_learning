#include<stdio.h>

void call_by_val_swap(int fvalue, int svalue);
void call_by_ref_swap(int *fvalue, int *svalue);

int main(){
    int fvalue = 100;
    int svalue = 200;

    printf("Before swaping value of fvalue : %d\n",fvalue);
    printf("Before swaping value of svalue : %d\n",svalue);
    call_by_val_swap(fvalue, svalue);
    printf("After swaping value of fvalue : %d\n",fvalue);
    printf("After swaping value of svalue : %d\n",svalue);

    printf("Before swaping value of fvalue : %d\n",fvalue);
    printf("Before swaping value of svalue : %d\n",svalue);
    call_by_ref_swap(&fvalue, &svalue);
    printf("After swaping value of fvalue : %d\n",fvalue);
    printf("After swaping value of svalue : %d\n",svalue);

}

void call_by_ref_swap(int *fvalue, int *svalue){
    int temp = 0;
    temp = *fvalue;
    *fvalue = *svalue;
    *svalue = temp;
}

void call_by_val_swap(int fvalue, int svalue){
    int temp = 0;
    temp = fvalue;
    fvalue = svalue;
    svalue = temp;
}

