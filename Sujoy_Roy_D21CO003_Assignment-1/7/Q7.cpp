#include <iostream>
#include <algorithm>
#include <chrono>
#include <time.h>

using namespace std;
using namespace std::chrono;

int code1(int n)
{
    int i, j;
    int x = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            x = x + 1;
    }
    return x;
}

int code2(int n)
{
    int i, x = 0;
    int j = n;
    while (j >= 1)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (i = 1; i <= j; i++)
        {
            x = x + 1;
        }
        j = n / 2;

        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        auto nanoseconds = (elapsed).count();
        if (nanoseconds >= 5)
            break;
    }

    return x;
}

int code3(int n)
{
    int i, j, x = 0, k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            for (k = 1; k <= i; k++)
                x = x + 1;
        }
    }

    return x;
}

int code4(int n)
{

    int j, x = 0, i = n;
    while (i >= 1)
    {
        for (j = 1; j <= n; j++)
            x = x + 1;
        i = i / 2;
    }

    return x;
}

int main()
{
    int n, a, b, c, d;

    cout << "Enter the value of n(prefer heigher value of ni.e n<10000):\n";
    cin >> n;

    auto start = std::chrono::high_resolution_clock::now();
    a = code1(n);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    auto nanoseconds = (elapsed).count();
    cout << "\nTime taken by function 1:" << nanoseconds << " nanoseconds" << endl;
    cout << a << "\n";

    start = std::chrono::high_resolution_clock::now();
    b = code2(n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    nanoseconds = (elapsed).count();
    cout << "\nTime taken by function 2:" << nanoseconds << " nanoseconds" << endl;
    cout << b << "\n";

    start = std::chrono::high_resolution_clock::now();
    c = code3(n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    nanoseconds = (elapsed).count();
    cout << "\nTime taken by function 3:" << nanoseconds << " nanoseconds" << endl;
    cout << c << "\n";

    start = std::chrono::high_resolution_clock::now();
    d = code4(n);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    nanoseconds = (elapsed).count();
    cout << "\nTime taken by function 4:" << nanoseconds << " nanoseconds" << endl;
    cout << d << "\n";

    return 0;
}
