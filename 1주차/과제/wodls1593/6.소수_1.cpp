#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000
bool Squrt(int n){
    if(n == 1) return false;
    for (int i = 2; i * i <= n ; i++)
    {
        if(n % i==0)
            return false;
    }
    return true;

}
int main() {

    int M, N;
    int sum =0;
    int min =0;
    cin >> M >> N;

    for(int i = M; i * i<=N; i++){
        if(Squrt(i)){
            sum += i;
            (min == 0) ? min = i : i=min;
        }

    }
    cout << sum <<"\n"<<min;
}