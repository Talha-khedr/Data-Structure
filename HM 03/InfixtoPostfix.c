#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }

        else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
