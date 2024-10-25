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

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++)
        d[i] = x[i + 1] - x[i];

    int gcd = GetListGCD(d);

    int result = 0;
    for (int i = 0; i < n - 1; i++)
        result += (d[i] / gcd - 1);
    cout << result << '\n';
}