#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1)
        return 0;
    else
        return stack[top--];
}

int isoper(char ch) {
    return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}

char* strrev(char* str) {
    int len = strlen(str);
    int sdx = 0, edx = len - 1;
    char tmp;

    if (len == 0)
        return 0;
    else {
        while (sdx < edx) {
            tmp = str[sdx];
            str[sdx] = str[edx];
            str[edx] = tmp;
            sdx++;
            edx--;
        }
    }

    return str;
}

int main(void) {
    char post[SIZE], inex[SIZE] = { 0 };
    int j = 0;

    scanf("%s", post);

    strrev(post);

    for (int i = 0; i < strlen(post); i++) {
        if (isoper(post[i])) {
            push(post[i]);
        }
        else {
            inex[j++] = post[i];
            inex[j++] = pop();
        }
    }

    inex[j] = '\0';

    strrev(inex);

    printf("%s", inex);

    return 0;
}
//AB*C+
//ABC/-AK/L-*

//before or after () adding?