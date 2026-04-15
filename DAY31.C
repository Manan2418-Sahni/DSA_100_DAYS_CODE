#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int x) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = x;
}

// Pop operation
void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
    top--;
}

// Display operation
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int op;
        scanf("%d", &op);

        if(op == 1) {
            int val;
            scanf("%d", &val);
            push(val);
        }
        else if(op == 2) {
            pop();
        }
        else if(op == 3) {
            display();
        }
    }

    return 0;
}