#include <stdio.h>
#include <stdlib.h>

int * swap(int * a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    return a;
}
int * selection(int * a, int d)
{
    int min, i, j;
    for(i = 0; i < d; i++)
    {
        min = i;
        for(j = i + 1; j < d; j++)
        {
            if(a[j] < a[min])
                min = j;
        }
        a = swap(a, min, i);
    }
    return a;
}
void print(int * a, int d)
{
    int i;
    for(i = 0; i < d; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int n, * arr, i;
    arr = (int *) malloc(sizeof (int));
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr = selection(arr, n);
    print(arr, n);
    free(arr);
    return 0;
}
