#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

void infixToPostfix(char Q[], char P[]) {

    int i = 0;
    int j = 0;

    push('(');

    while (Q[i] != '\0') {

        char ch = Q[i];

        if (isalnum(ch)) {
            P[j++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            while (precedence(peek()) >= precedence(ch)) {
                P[j++] = pop();
            }

            push(ch);
        }

        else if (ch == ')') {

            while (peek() != '(') {
                P[j++] = pop();
            }

            pop(); 
        }

        i++;
    }

    Q[i] = ')';
    Q[i + 1] = '\0';

    while (peek() != '(') {
        P[j++] = pop();
    }

    pop(); 

    P[j] = '\0';
}

int main() {

    char Q[MAX] = "A+B*C";
    char P[MAX];

    infixToPostfix(Q, P);

    printf("Postfix: %s\n", P);

    return 0;
}