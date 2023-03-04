#include<stdio.h>
/* Bit-wise :
* Its a concept of using memory optimized way.
* Its only used for struct and can be used for union as well but any ways
    union gonna use larger memory of the meber inside it so its only useful 
    for struct.
* We should use bit wise only when we know how much or limit our member 
    in struct gonna take at max.
* So we con define the limit for our meber in bit format like (1,2,3,4,e.t.c).
* 1 = (0,1), 2= (00,01,10,11), 3 = (000,001,010,011,100,101,110,111)
    so in about example 1 can store 1 or 0, 2 can store (0 to 3)
    3 can store upto 7. so we can define the range in bit format 
* If the value lie outside of the range then the data is trancated to its max limit.
* The size are allocate in x4 byte .
* It works only on int data type or supported data type by bits.s
syntax:
struct {
    unsigned int age :4;-> Here age can hold upto 4 bit data for 0 to 64
    member : bit_limt 
}
*/
struct 
{
    int book_id:4;
    int row_index:3;
    int ref_id:4;

} book_record;

int main(){
    printf("Size of book_record : %d\n", sizeof(book_record));
}