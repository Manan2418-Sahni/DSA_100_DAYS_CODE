#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push
void push(int x) {
    if(top == MAX - 1) {
        return;
    }
    stack[++top] = x;
}

// Pop
void pop() {
    if(top == -1) {
        return;
    }
    top--;
}

// Display
void display() {
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Push all elements
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    int m;
    scanf("%d", &m);

    // Pop m elements
    for(int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}