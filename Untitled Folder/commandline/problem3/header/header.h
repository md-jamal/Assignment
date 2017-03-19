#include <stdio.h> //include stdio.h library
#include <stdlib.h> //include atdlib
#define MAX 64 //macro to define value of MAX

void add (int a,int b); //function to add two numbers
void sub (int a,int b); //function to subtract two numbers
void mul (int a,int b); //function to multiply two numbers
void divi (int a,int b); //function to divide two numbers

//array of function pointers
//void (*calculators[]) (int a,int b) = {add,sub,mul,div}; 
