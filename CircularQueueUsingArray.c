#include <stdio.h>
// #include <Windows.h>
#define SIZE 5
int a[SIZE];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if ((rear + 1) % SIZE == front)
    {
        printf("queue is full\n");
        return;
    }
    else
        rear = (rear + 1) % SIZE;
    a[rear] = x;
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is empty \n");
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
        front = (front + 1) % SIZE;
}
int Peek()
{
    if (a[front] == -1)
        return -1;
    return a[front];
}
void Print()
{
    int count = ((rear + SIZE - front) % SIZE) + 1;
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%d ", a[(front + i) % SIZE]);
    }
    printf("\n");
}
int main(void)
{
    enqueue(5);
    printf("\nFirst insertion in circular Queue\n");
    Print();
    printf("\n Second insertion in circular Queue\n");
    enqueue(7);
    Print();
    printf("\n Third insertion in circular Queue\n");
    enqueue(-3);
    Print();
    printf("\n Fourth insertion in circular Queue\n");
    enqueue(9);
    Print();
    printf("\n Circular Queue after first deletion\n");
    dequeue();
    Print();
    printf("\n Circular Queue after 2nd deletion\n");
    dequeue();
    Print();
    printf("\n Insertion in circular Queue\n");
    enqueue(14);
    system("pause");
    return 0;
}
