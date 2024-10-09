#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <chrono>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 200'000

bool BruteTest(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool SqrtTest(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool SieveTest(int n)
{
    static vector<int> isPrime(MAX + 1, true);
    static bool isInited = false;

    if (!isInited)
    {
        isInited = true;

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= MAX; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i + i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime[n];
}

template <typename T, typename... Args>
auto MeasureTime(T func, int n = MAX)
{
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i <= n; i++)
        func(i);

    auto end = chrono::high_resolution_clock::now();
    auto dt = chrono::duration_cast<chrono::microseconds>(end - start).count();
    return dt;
}

int main()
{
    FastIO;

    cout << "brute test start" << '\n';
    auto dt = MeasureTime(BruteTest);
    cout << "brute test time: " << dt << '\n';
    cout << '\n';

    ////////////////////////////////////////////

    cout << "sqrt test start" << '\n';
    dt = MeasureTime(SqrtTest);
    cout << "sqrt test time: " << dt << '\n';
    cout << '\n';

    ////////////////////////////////////////////

     /*
      * isPrime 미리 초기화해놓기
      * 이걸 precomputation, 일명 런타임 전의 전처리 라고 부름
      */

    cout << "seive init start" << '\n';
    dt = MeasureTime(SieveTest, 0);
    cout << "sieve init time: " << dt << '\n';
    cout << '\n';

    ////////////////////////////////////////////

    cout << "seive test start" << '\n';
    dt = MeasureTime(SieveTest);
    cout << "sieve test time: " << dt << '\n';
    cout << '\n';
}