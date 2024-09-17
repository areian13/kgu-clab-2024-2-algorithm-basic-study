#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 4'000'000

void MakePrimes(vector<int>& primes)
{
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        primes.push_back(i);
        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }
}

int main()
{
    FastIO;

    int n;
    cin>>n;

    vector<int> primes;
    MakePrimes(primes);

    int result = 0;
    int p = primes.size();
    for (int i = 0; i < p; i++)
    {
        int sum = 0;
        for (int j = i; j < p && sum < n; j++)
        {
            sum += primes[j];
            if (sum == n)
            {
                result++;
                break;
            }
        }
    }
    cout << result << '\n';
}