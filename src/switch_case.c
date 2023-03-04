#include<stdio.h>
/*
Switch case :
It is used to compare a varaible with n number same iterals 
and excute the case block if the given case iteral is equal

Breaks statement needs to be in every block if not 
contiune of statement will contine till break statement terminats

default is optional will excute when no contion is matched.

The following rules apply to a switch statement −

The expression used in a switch statement must have an integral or enumerated type,
or be of a class type in which the class has a single conversion 
function to an integral or enumerated type.

You can have any number of case statements within a switch. 
Each case is followed by the value to be compared to and a colon.

The constant-expression for a case must be the same data type as the variable in the switch,
and it must be a constant or a literal.

When the variable being switched on is equal to a case,
the statements following that case will execute until a break statement is reached.

When a break statement is reached, the switch terminates, and the flow of control 
jumps to the next line following the switch statement.

Not every case needs to contain a break. If no break appears, the flow of control 
will fall through to subsequent cases until a break is reached.

A switch statement can have an optional default case, which must appear at the end of the switch. 
The default case can be used for performing a task when none of the cases is true. No break is needed in the default case.

syntax:
switch(varaible){
    case consts:
        true block;
        break;
    case consts:
        true block;
        break;
    default:
        true block;
        // no need for break in default
}
*/
int main(){
    int total = 650;
    switch(total){
        case (500):
            puts("You have got mark grater than 500");
            break;
        case (600):
            puts("You have got mark less than 600");
            break;
        default:
            puts("Value not found");
    }
}