#include<stdio.h>
#include<stdlib.h>

int front, rear;
int size();
int empty();
int * enq(int *, int);
void deq(int *);///////////////////////////////////////////////////////////////
void print(int *);


//_________________________________________________________________________________________
int main()
{
  int * queue;
  int max;
  scanf("%d", &max);
  queue = (int *) malloc (max * sizeof(int));
  front = rear = 0;
  for(int i = 0; i < 30; i++)
  {
    print(queue);
    queue = enq(queue, i);
  }
  for(int i = 0; i < 9; i++)
  {
    print(queue);
  //  deq(queue);
  }

  print(queue);
  free(queue);
  return 0;
}
//___________________________________________________________________________________________


int size()
{
  return (rear - front);
}

int empty()
{
  if(rear == 0)
  {
    return 1;
  }
  return 0;
}

int * enq(int * q, int d)
{
  q[rear] = d;
  rear++;
  return q;
}

void deq(int * q)
{
  front++;
}

void print(int * q)
{
  for(int i = front; i < rear; i++)
  {
    printf("%d ", q[i]);
  }
  printf("\n");
}
