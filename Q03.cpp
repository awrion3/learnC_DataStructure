#include <iostream>

#define SIZE 100

using namespace std;

string stack[SIZE];
int top = -1;

void push(string str) {
    stack[++top] = str;
}

string pop() {
    if (top == -1)
        return "";
    else
        return stack[top--];
}

string peek() {
    if (top == -1)
        return "";
    else 
        return stack[top];
}

bool isOperand(char x) {
    return (x >= 'A' && x <= 'Z');
}

int main(void) {
    string exp;

    cin >> exp;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isOperand(exp[i])) {
            string op(1, exp[i]);
            
            push(op);
        }
        else {
            string op1 = pop();
            string op2 = pop();
            
            push("(" + op2 + exp[i] + op1 + ")");
        }
    }

    cout << peek();

    return 0;
}
//ABC/-AK/L-*