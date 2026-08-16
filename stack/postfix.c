//postfix evaluation
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int eval(char P[]){
    int i=0;

    while (1){
        char ch = P[i++];

        if (isdigit(ch)) {
            push(ch - '0');
        }else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            int A = pop();
            int B = pop();
                      
            int result;

            switch (ch) {
                case '+': result = B + A; break;
                case '-': result = B - A; break;
                case '*': result = B * A; break;
                case '/': result = B / A; break;
            }

            push(result);
        }else if (ch==')'){
            return stack[top];
        }
    }
}

int main(){
    char P[] = "23+45-*)";

    printf("Result = %d\n", eval(P));

    return 0;
}