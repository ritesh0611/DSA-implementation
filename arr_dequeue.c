#include<stdio.h>
#include<stdlib.h>

int front, rear;
int size();
int empty();
int * enq_front(int *, int);
int * enq_rear(int *, int);
void deq_front(int *);
void deq_rear(int *);
void print(int *);

int main()
{
  front = rear = 0;
  int max;
  scanf("%d", &max);
  int * deque;
  deque = (int *) malloc (max * sizeof(int));

  free(deque); 
  return 0;
}

int size()
{
  return (rear - front);
}

int empty()
{
  if(front - rear == 0)
  {
    return 1;
  }
  return 0;
}

int * enq_front(int * dq, int d)
{
  
}

int * enq_rear(int * dq, int d)
{
  dq[rear] = dq[d];
  rear++;
  return dq;
}

void deq_front(int * dq)
{
  front++;
}

void deq_rear(int * dq)
{
}

void print(int * dq)
{
  for(int i = front; i < rear; i++)
  {
    printf("%d ", dq[i]);
  }
  printf("\n");
}


















