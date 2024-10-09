#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ctod(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

char dtoc(int d)
{
    if (0 <= d && d <= 9)
        return d + '0';
    return d - 10 + 'A';
}

int BaseToDec(string& num, int from)
{
    int digit = num.size();

    int result = 0;
    int power = 1;
    for (int i = digit - 1; i >= 0; i--)
    {
        result += ctod(num[i]) * power;
        power *= from;
    }
    return result;
}

string DecToBase(int num, int to)
{
    string result = "";
    do
    {
        result += dtoc(num % to);
        num /= to;
    } while (num > 0);

    reverse(result.begin(), result.end());
    return result;
}

string BaseConversion(string& num, int from, int to)
{
    // from진수에서 10진수로, 10진수에서 to진수로
    return DecToBase(BaseToDec(num, from), to);
}

int main()
{
    FastIO;

    while (true)
    {
        string num;
        int from, to;
        cin >> num >> from >> to;

        if (cin.eof())
            break;

        string result = BaseConversion(num, from, to);
        printf("%s(%d) is %s(%d)\n", num.c_str(), from, result.c_str(), to);
        printf("\n");
    }
}