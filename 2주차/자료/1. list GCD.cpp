#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int GetListGCD(vector<int>& list)
{
    int n = list.size();

    int gcd = 0;
    for (int i = 0; i < n; i++)
        gcd = GCD(gcd, list[i]);
    return gcd;
}

int main()
{
    FastIO;

    vector<int> list = { 16,32,12,28 };

    int gcd = GetListGCD(list);
    cout << gcd <<'\n';
}