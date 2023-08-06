#include <stdio.h>
#include <stdlib.h>

int max, front, rear;
int * enqueue(int * a, int d)
{
    a[rear] = d;
    rear++;
    return a;
}
void dequeue()
{
    front++;
}

int main()
{
    front = rear = 0;
    max = 1000;
    int * queue;
    queue = (int *) malloc (sizeof (int) * max);

    free(queue);

    return 0;
}