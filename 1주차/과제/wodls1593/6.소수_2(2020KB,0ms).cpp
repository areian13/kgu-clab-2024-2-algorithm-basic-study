#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000
bool Cae(int n){
    static vector<int> isPrime(MAX + 1, true);
    static bool isInited = false;
    if(!isInited){
        isInited = true;
        
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i<=MAX; i++){
            if(!isPrime[i]) continue;
            for(int j = i * i; j<=MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
    return isPrime[n];
}

int main(){
    int M, N;
    cin >> M >> N;
    int sum =0;
    int min =0;
    for(int i=M;i<=N;i++){
        if(Cae(i)){
            sum += i;
            (min==0) ? min = i : min = min;
        }
    }
    if(sum ==0) cout << -1;
    else
        cout << sum << '\n' << min;
}