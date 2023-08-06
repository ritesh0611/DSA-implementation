#include <stdio.h>
#include <stdlib.h>
int * swap(int * a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    return a;
}
int * insertion(int * a, int d)
{
    int i;
    for(i = 0; i < d - 1; i++)
    {
        int tmp, j;
        j = i + 1;
        tmp = a[j];
        while(a[j - 1] > tmp && j > 0)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = tmp;
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

int main()
{
    int n, * arr, i;
    arr = (int *) malloc(sizeof (int));
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr = insertion(arr, n);
    print(arr, n);

//    free(arr);
    return 0;
}
