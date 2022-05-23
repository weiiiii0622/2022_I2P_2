#include "stdbool.h"

// c = a + b;
void add(int a[100], int b[100], int c[100])
{
    for (int i=0; i<100; i++)   // 對應的位數相加
        c[i] = a[i] + b[i];

    for (int i=0; i<100-1; i++) // 一口氣進位
    {
        c[i+1] += c[i] / 10;    // 進位
        c[i] %= 10;             // 進位後餘下的數
    }
}

void sub(int a[100], int b[100], int c[100])
{
    for (int i=0; i<100; i++)
        c[i] = a[i] - b[i];

    for (int i=0; i<100-1; i++) // 一口氣借位和補位
        if (c[i] < 0)
        {
            c[i+1]--;           // 借位
            c[i] += 10;         // 補位
        }
}

void mul(int a[100], int b[100], int c[100])
{
    for (int i=0; i<100; i++)
        c[i] = 0;

    for (int i=0; i<100; i++)
        for (int j=0; j<100; j++)
            if (i+j < 100)
                c[i+j] += a[i] * b[j];

    for (int i=0; i<100-1; i++) // 一口氣進位
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
}

void mul_int(int a[100], int b, int c[100])
{
    for (int i=0; i<100; i++)
        c[i] = a[i] * b;

    for (int i=0; i<100-1; i++) // 一口氣進位
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
}

void div(int a[100], int b[100], int c[100])
{
    int t[100];

    for (int i=100-1; i>=0; i--)
        for (int k=9; k>0; k--) // 嘗試商數
        {
            mul(b+i, k, t);
            if (!less_than(a+i, t))
            {
                sub(a+i, t, c+i);
                break;
            }
        }
}

void div(int a[100], int b, int c[100])
{
    int r = 0;
    for (int i=100-1; i>=0; i--)
    {
        r = r * 10 + a[i];
        c[i] = r / b;
        r %= b;
    }
}


//utility

bool less_than(int a[100], int b[100])
{
    // 從高位數開始比，對應的位數相比較。
    for (int i=100-1; i>=0; i--)
        if (a[i] != b[i])   // 一旦ab不一樣大，馬上回傳結果。
            return a[i] < b[i];
    return false;   // 完全相等
}

bool prime[20000000];

void eratosthenes()
{
    for (int i=0; i<20000000; i++)
        prime[i] = true;

    prime[0] = false;
    prime[1] = false;

    for (int i=2; i<20000000; i++)
        if (prime[i])
            // 刪掉質數i的倍數，從i倍開始。小心溢位。
            for (int j=i*i; j<20000000; j+=i)
                prime[j] = false;
}