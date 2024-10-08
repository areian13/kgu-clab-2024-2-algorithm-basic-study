#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)//최대공약수
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)//최소공배수
{
    return a * b / GCD(a, b);
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;
    int gcd = GCD(a,b);
    int lcm = LCM(a,b);
    cout << gcd << "\n";
    cout << lcm << "\n";

}