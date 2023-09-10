#include <stdio.h>
#include "boolean.h"

int main()
{
    int n, i, count;
    scanf("%d", &n);
    // 2 3 5 7 11 101 10301 929
    count = 0;
    i = 2;
    while (count != n)
    {
        if (CekPalindromPrima(i))
        {
            count += 1;
        }
        i++;
    }
}

boolean CekPalindromPrima(int n)
{
    int i, len;
    len = length(n);
    // palindrom
    for (i = 0; i < len / 2; i++)
    {
        if (n % pow(10, i + 1) != n / pow(10, len - 1))
        {
            return false;
        }
    }

    // bilangan prima
}

int length(int n)
{
    int count, i;
    count = 0;
    while (n > 0)
    {
        count += 1;
        n /= 10;
    }
    return count;
}

int pow(int a, int b)
{
    int res, i;
    res = 1;
    for (i = 0; i < b; i++)
    {
        res *= b;
    }
    return res;
}