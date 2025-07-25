#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>

//Fuction Declarations
void tell_time();



int main(){
    printf("Hi, I am Benga \n");

    tell_time();
}

//Time Module

void tell_time(){
    time_t t;

    time (&t);
    printf("Current time is %s", ctime(&t));
}