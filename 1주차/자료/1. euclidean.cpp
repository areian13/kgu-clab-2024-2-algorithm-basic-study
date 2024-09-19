#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    FastIO;

    while (true)
    {
        int a, b;
        cin >> a >> b;

        if (cin.eof())
            break;

        printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));
        printf("LCM(%d, %d) = %d\n", a, b, LCM(a, b));
        printf("\n");
    }
}