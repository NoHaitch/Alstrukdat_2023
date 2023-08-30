#include <stdio.h>

int main()
{
    int n, count, sum;
    count = 0;
    sum = 0;
    scanf("%d", &n);
    do
    {
        sum += n % 10;
        n /= 10;
        ++count;
    } while (n != 0);
    printf("%d\n", sum);

    return 0;
}