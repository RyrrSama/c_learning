#include<stdio.h>
// Its a inbuild library used to hold complier range deatils macros.
#include<limits.h>

int main(){
    // Int is a interger data type
    // Int can hold postive as well negtive value
    // Its called signed Int which is int.
    int number = 24 ;
    // INT_MIN used to tell complier int data type min range supported 
    // INT_MAX used to tell complier int data type max range supported 
    printf("Interger Minimum Value : %d\n", INT_MIN);
    printf("Interger Maximum Value : %d\n", INT_MAX);
    // uint or unsigned int is used to stored only postive value.
    // uint is not standard so use unsigned int always.
    // uint is min is zero 
    // It can never be over fill it cycle inside 0 to UINT_MAX.
    // So adding UNIT_MAX + 1 result in 0.
    unsigned int age = 25; // age can never be less then zero so using uint
    printf("Unsigned interger Minimum Value : %d\n", 0);
    printf("Unsigned interger Maximum Value : %d\n", UINT_MAX);
    // Char is used to store number as well single char in alpabet between 0 to 255.
    // signed or char can store from -125 to 124.
    // unsigned char can store from 0 to 255.
    // char takes 1 byte size to store.

    unsigned char car_speed = 254;
    printf("%d",car_speed);

    // Short used to some values than interger.
    // It takes 2 bytes to stort a short value.
    // values ranges from -32,786 to 32,786.
    unsigned short km_travalled = 30000;
    printf("%d\n", km_travalled);

    // This is the longest values can be.
    // Uesd form calculation mostly.
    // It takes 8 or 4 byte for 323 bit system.
    unsigned long distance_from_sun = 3450000000;

    // sizeof() is used to return the memory took a system to store a object non varable.
    // It returns value in byte.
    // it is useful to locate next item in array by using array type.
    // and also useful to point next pointer for same datatype.
    printf("%d", sizeof(int));// returns 4.

    // Notes on Puts() and printf()
    // puts() cant display non string char* only const char * supported.
    // printf() is used to display string formatting.(pattern, values).
    // puts() breaks line automatically but printf() dont.


}