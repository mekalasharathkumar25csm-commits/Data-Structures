#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push an operator or bracket onto the stack */
void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

/* Pop an operator or bracket from the stack */
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

/* Return precedence of an operator */
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

/* Check whether a character is an operator */
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '^');
}

/* Convert infix expression to postfix */
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            /* Operand: copy directly to output */
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else if (isOperator(ch)) {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch)
                   && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    /* Pop all remaining operators */
    while (top != -1) {
        if (stack[top] == '(') {
            pop();
            continue;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

/* Main function */
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}