#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


char dtoc(int n){
    if(n>=0 && n<=9)
        return n + '0';
    return n - 10 + 'A';
}

string DecToBase(int n, int b){
    string result = "";

    do{
        result += dtoc(n%b);
        n /=b;
    }while(n>0);
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    int N, B;
    cin >> N >> B;

    cout << DecToBase(N,B);

}