#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((front == (rear + 1) % MAX));
}

// push_front
void push_front(int x) {
    if(isFull()) return;

    if(isEmpty()) {
        front = rear = 0;
    }
    else if(front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    dq[front] = x;
}

// push_back
void push_back(int x) {
    if(isFull()) return;

    if(isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    dq[rear] = x;
}

// pop_front
void pop_front() {
    if(isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if(isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if(front == rear) {
        front = rear = -1;
    }
    else if(rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

// front element
void getFront() {
    if(isEmpty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

// back element
void getBack() {
    if(isEmpty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

// size
void size() {
    if(isEmpty()) {
        printf("0\n");
        return;
    }

    if(rear >= front)
        printf("%d\n", rear - front + 1);
    else
        printf("%d\n", MAX - front + rear + 1);
}

// display
void display() {
    if(isEmpty()) return;

    int i = front;
    while(1) {
        printf("%d ", dq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        int op, val;

        scanf("%d", &op);

        switch(op) {
            case 1: scanf("%d", &val); push_front(val); break;
            case 2: scanf("%d", &val); push_back(val); break;
            case 3: pop_front(); break;
            case 4: pop_back(); break;
            case 5: getFront(); break;
            case 6: getBack(); break;
            case 7: size(); break;
            case 8: display(); break;
        }
    }

    return 0;
}