#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    FastIO;

    int m,n;
    cin >> m >> n;
    int sum = 0;
    int min = 0;
    for(int i = m; i<=n; i++){
        if(isPrime(i)){
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