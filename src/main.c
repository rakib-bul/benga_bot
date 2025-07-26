#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>

//Fuction Declarations
void chatbot();
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


//chatbot

void chatbot(){
    char input[100];

    while (1){
        printf("user: \n");

        fgets(input, sizeof(input), stdin);
        input[strspn(input, "/n")] == 0;

        if (strcmp(input, "Exit") == 0){
            printf("Good bye /n");
            break;
        }

    }

    const char* intent = classify(input);

    if (strcmp(intent, "GREET") == 0){
        printf("Benga: Hello there \n");
    }

    printf("It's a bot");
}
