#include <stdio.h>

int main()
{
    int n, i, sum;
    i = 0;
    sum = 0;
    scanf("%d", &n);
    while (i < 4)
    {
        sum += n % 10;
        n = (n - (n % 10)) / 10;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}