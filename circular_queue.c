#include<stdio.h>
#include<stdlib.h>

int front, rear;

int size();
int empty();
int * enqueue(int *, int, int);
void dequeue(int *, int);
void Print(int *, int);

int main()
{
  front = rear = 0;
  int size;
  scanf("%d", &size);
  int * queue;
  queue = (int *) malloc (size * sizeof(int));
  
  return 0;
}

int size()
{
}

int empty()
{
}

int * enqueue(int * q, int d, int sz)
{
  q[rear] = d;
  rear = (rear + 1) % sz;
  return q;
}

void dequeue(int * q, int sz)
{
  front = (front + 1) % sz;
}

int top()
{
}

void print(int * q, int sz)
{
  for(int i = front; i < rear
}
