#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if((rear + 1) % MAX == front) {
        return; // Queue full
    }

    if(front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
}

// Dequeue
void dequeue() {
    if(front == -1) {
        return; // Queue empty
    }

    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Display
void display() {
    if(front == -1) {
        return;
    }

    int i = front;
    while(1) {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}