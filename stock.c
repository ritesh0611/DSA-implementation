#include <stdio.h>
#include <stdlib.h>
/*
int * span(int * a, int d)
{
    int * s;
    s = (int *) calloc(d, sizeof (int));
    int i, j;
    for(i = 0; i <d; i++)
        s[i] = 1;
    for(i = 1; i < d; i++)
    {
        j = i - 1;
        while(j >= 0 && a[i] >= a[j])
        {
            s[i]++;
            j--;
        }
    }
    return s;
}
 */
int * span(int * a, int d)
{
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
    scanf("%d", &n);
    arr = (int *) malloc (n * sizeof (int));
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr = span(arr, n);
    print(arr, n);
    free(arr);
    return 0;
}