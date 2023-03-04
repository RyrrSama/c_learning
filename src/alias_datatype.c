#include<stdio.h>
/*
typedef:
* The C programming language provides a keyword called typedef, 
which you can use to give a type a new name.

*By convention, uppercase letters are used for these definitions to remind 
the user that the type name is really a symbolic abbreviation, 
but you can use lowercase.

*You can use typedef to give a name to your user defined data types as well.

#define:
* #define is a C-directive which is also used to define the aliases for various data values.

* typedef is limited to giving symbolic names to types only 
where as #define can be used to define alias for values,
you can define 1 as ONE etc.

NOTE:
*typedef interpretation is performed by the compiler 
*whereas #define statements are processed by the pre-processor.
* typedef can used only to set alias name for datatype.
* #define can be used only to set alias name for datatype value.
*/

#define MAX_LIMIT 2000

typedef unsigned int POSTIVE_INT;

int main(){

    POSTIVE_INT age = 25;
    POSTIVE_INT distance = 35;
    return 0;

}