#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue penuh!\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueue %d\n", value);
    }
}

// Dequeue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue kosong!\n");
    } else {
        printf("Dequeue %d\n", queue[front]);
        front++;
    }
}

// Tampil
void display() {
    if (front == -1 || front > rear) {
        printf("Queue kosong\n");
    } else {
        printf("Isi queue:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    dequeue();
    display();
    return 0;
}
