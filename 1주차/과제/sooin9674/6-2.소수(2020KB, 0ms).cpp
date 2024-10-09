#include <iostream>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define MAX 10'000
using namespace std;

int IsPrime(int n){
    static vector<bool> isPrime(MAX + 1, true);
    static bool isInited = false;

    if(!isInited){
        isInited = true;
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=MAX; i++){
            if(!isPrime[i])
                continue;
            for(int j= i*i; j<=MAX; j+=i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime[n];
}

int main()
{
    FastIO;
    
    int m,n;
    cin >> m >> n;
    int sum = 0;
    int min = 0;
    for(int i = m; i<=n; i++){
        if(IsPrime(i)){
            sum += i;
            min = (min == 0? i : min);
        }
    }
    if( sum == 0){
        cout << -1 << "\n";
    }else{
        cout << sum << "\n";
        cout << min << "\n";
    }


}