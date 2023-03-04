#include<stdio.h>

/*
What is struct:
    *Structure is another user defined data type available in C 
    that allows to combine data items of different kinds.
    *Structures are used to represent a record.

Defining a Structure
    *To define a structure, you must use the struct statement. 
    *The struct statement defines a new data type, with more than one member.

Syntax:
    struct [structure tag] {

    member definition;
    member definition;
    ...
    member definition;
    } [one or more structure variables];  

    *The structure tag is optional
    *At the end of the structure's definition, before the final semicolon,
    You can specify one or more structure variables but it is optional.

Accessing Structure Members:
    *To access any member of a structure, we use the member access operator (.). 
    *The member access operator is coded as a period between the structure variable name.

Declaration:
    *You would use the keyword struct to define variables of structure type. 

Structures as Function Arguments:
    *You can pass a structure as a function argument in the same way as you pass any other variable or pointer.
Syntax:
    void printBook( struct Books book );

Pointers to Structures:
    *You can define pointers to structures in the same way as you define pointer to any other variable
    *you can store the address of a structure variable in the above defined pointer variable using &
    *To find the address of a structure variable, place the '&'; operator before the structure's name 
    *To access the members of a structure using a pointer to that structure, you must use the → operator

Syntax:
    struct Books *struct_pointer;
    struct_pointer = &Book1;
    struct_pointer->title;s
*/
struct Book {
    char author [40];
    char title[50];
    char subject[40];
    int book_id;
};

int main(){

    struct Book book_obj_1;
    strcpy(book_obj_1.author, "Ramkumar.E");
    strcpy(book_obj_1.title, "C Programming");
    strcpy(book_obj_1.subject, "Programming");
    strcpy(book_obj_1.book_id, 1001);

    printf("book 1 author name : %s", book_obj_1.author);
    printf("Book 1 title name : %s", book_obj_1.title);
    printf("Book 1 subject name : %s", book_obj_1.subject);
    printf("Book 1 book id : %d", book_obj_1.book_id);

}