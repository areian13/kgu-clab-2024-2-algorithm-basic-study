#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ctod(char c){
    if('0'<=c && c<='9')
        return c-'0';
    return c-'A'+10;
}

int BaseToDec(string& n, int b){
    int d = n.size();
    int result = 0;
    int power = 1;

    for(int i = d - 1; i >= 0; i--){
        result += ctod(n[i]) * power;
        power *= b;
    }

    return result;
}

int main()
{
    FastIO;
    
    string n;
    int b;
    cin >> n >> b;
    int result = BaseToDec(n,b);
    cout << result << "\n";

}