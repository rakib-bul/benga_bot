#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

// Function Declarations
void to_lowercase(char *str);
void show_happy();
void show_sad();
void show_neutral();
void tell_time();
void calculate_expression();
void translate();
void chatbot();

// Global Variables & Constants
char bot_name[10] = "Benga";

int main() {
    chatbot();
    return 0;
}

// Time Module (Fixed newline issue)
void tell_time() {
    time_t t;
    time(&t);
    char *timestr = ctime(&t);
    timestr[strcspn(timestr, "\n")] = '\0';  // Remove newline
    printf("%s:: Current time is %s\n", bot_name, timestr);
}

// Chatbot (Fixed function calls and buffer issues)
void chatbot() {
    char input[100];

    while (1) {
        printf("user: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        to_lowercase(input);

        if (strcmp(input, "exit") == 0) {
            printf(GREEN "%s : Good bye \n" RESET, bot_name);
            break;
        }
        else if (strstr(input, "hello")) {
            show_happy();
        }
        else if (strstr(input, "sad")) {
            show_sad();
        }
        else if (strstr(input, "time")) {
            tell_time();
        }
        else if (strstr(input, "do math")) {
            calculate_expression();
        }
        else if (strstr(input, "translate")) {
            translate();
        }
        else {
            show_neutral();
        }
    }
}

// Translate (Fixed buffer overflow and input clearing)
void translate() {
    char word[32];
    printf("Enter English word to translate: ");
    if (scanf("%31s", word) != 1) {  // Limit input length
        // Handle input error
    }
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    to_lowercase(word);
    if (strcmp(word, "hello") == 0)
        printf("Bangla: হ্যালো\n");
    else if (strcmp(word, "book") == 0)
        printf("Bangla: বই\n");
    else
        printf("Translation not found\n");
}

// Calculator (Added input buffer clearing)
void calculate_expression() {
    double a, b;
    char op;

    printf("%s : Enter expression (eg. 12+23): ", bot_name);
    if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
        // Handle input error
    }
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    switch(op) {
        case '+': printf("= %.2lf \n", a + b); break;
        case '-': printf("= %.2lf \n", a - b); break;
        case '*': printf("= %.2lf \n", a * b); break;
        case '/': 
            if (b != 0) printf("= %.2lf\n", a / b);
            else printf("Division by zero error!\n");
            break;
        default: printf("Unknown operator\n");
    }
}

// ASCII Emotions (Fixed neutral message)
void show_happy() {
    printf("%s : ^_^ I'm happy to help!\n", bot_name);
}

void show_sad() {
    printf("%s : ;_; Sorry to hear that.\n", bot_name);
}

void show_neutral() {
    printf("%s : :| I don't know that yet\n", bot_name);  // Combined message
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}