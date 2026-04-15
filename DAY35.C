#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if(rear == MAX - 1) {
        return; // overflow
    }

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

// Display
void display() {
    if(front == -1) {
        return;
    }

    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}