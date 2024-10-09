#include <iostream>

using namespace std;

int ctod(char c){
    if(c >='0' && c<='9')
        return c-'0';

    return c - 'A' + 10;
}

int BaseToDec(string& s, int b){
    int digit = s.size();
    int result = 0;
    int pow = 1;
    for(int i =digit-1; i>=0; i--){
        result += ctod(s[i]) * pow;
        pow *= b;
    }
    return result;
}

int main(){

    string N;
    int B;
    cin >> N >> B;
    cout << BaseToDec(N, B);


}