#include <stdio.h>
#include <stdlib.h>

int n;
int * swap (int * a, int i, int j)
{
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    return a;
}
int search(int * a, int d) {
    int i;
    for (i = 0; i < n; i++)
    {
        if(a[i] == d)
            break;
    }
    return i;
}
int * ins_end (int * a, int d)
{
    a = (int *) realloc (a, (n + 1) * sizeof (int));
    a[n] = d;
    n++;
    return a;
}
int * del_end (int * a, int d)
{
    a = (int *) realloc (a, (n -1) * sizeof (int));
    n--;
    return a;
}
int * max_heapify (int * a, int i)
{
    int lc, rc, larger;
    lc = 2 * i + 1;
    rc = 2 * i + 2;
    larger = i;
    if (a[lc] > a[larger] && lc < n)
        larger = lc;
    if (a[rc] > a[larger] && rc < n)
        larger = rc;
    if (larger != i)
    {
        a = swap(a, i, larger);
        a = max_heapify(a, larger);
    }
    return a;
}
int * min_heapify (int * a, int i)
{
    int lc, rc, smaller;
    lc = 2 * i + 1;
    rc = 2 * i + 2;
    smaller = i;
    if (a[lc] < a[smaller] && lc < n)
        smaller = lc;
    if (a[rc] < a[smaller] && rc < n)
        smaller = rc;
    if (smaller != i)
    {
        a = swap(a, i, smaller);
        a = min_heapify(a, smaller);
    }
    return a;
}
int * cons_maxH (int * a)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        a = max_heapify(a, i);
    }
    return a;
}
int * cons_minH (int * a)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        a = min_heapify(a, i);
    }
    return a;
}
int * ins_maxH (int * a, int d)
{
    a = ins_end(a, d);
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        a = max_heapify(a, i);
    }
    return a;
}
int * ins_minH (int * a, int d)
{
    a = ins_end(a, d);
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        a = min_heapify(a, i);
    }
    return a;
}
int * del_maxH (int * a, int d)
{
    int ind;
    ind = search(a, d);
    a = swap(a, ind, n - 1);
    a = del_end(a, d);
    a = max_heapify(a, ind);
    return a;
}
int * del_minH (int * a, int d)
{
    int ind;
    ind = search(a, d);
    a = swap(a, ind, n - 1);
    a = del_end(a, d);
    a = min_heapify(a, ind);
    return a;
}
int * maxH_sort(int * a)
{
    int tmp = n;
    while(n > 0)
    {
        a = swap(a, 0, n - 1);
        n--;
        a = max_heapify(a, 0);
    }
    n = tmp;
    return a;
}
void print (int * arr)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int * arr, i;
    scanf("%d", &n);
    arr = (int *) malloc (sizeof (int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
//    print(arr, n);
    arr = cons_maxH (arr);
    print(arr);
//    int del;
//   scanf("%d",&del);
//    printf("%d\n", n);
    arr = maxH_sort(arr);
    print(arr);

    free(arr);

    return 0;
}