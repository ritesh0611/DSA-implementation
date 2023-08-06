#include <stdio.h>
#include <stdlib.h>

int * swap(int * a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    return a;
}
int * bubble(int * a, int d)
{
    int i, j, flag;
    flag = 1;
    for(i = 0; i < d - 1; i++)
    {
        for(j = 0; j < d - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                a = swap(a, j, j + 1);
                flag = 0;
            }
        }
        if(flag == 1)
            break;
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
    arr = (int *) malloc(n * sizeof (int));
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr = bubble(arr, n);
    print(arr, n);

    free(arr);
    return 0;
}
