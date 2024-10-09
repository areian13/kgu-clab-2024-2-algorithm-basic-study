#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000
bool Squrt(int n){
    if(n == 1) return false;
    if(n == 2) return true;
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
    
    for(int i = M; i <=N; i++){
        if(Squrt(i)){
            sum += i;
            (min == 0) ? min = i : min=min;
        }

    }
    if(sum == 0)
    {
        cout << "-1";
        return 0;
    }
    cout << sum <<"\n"<<min;
}