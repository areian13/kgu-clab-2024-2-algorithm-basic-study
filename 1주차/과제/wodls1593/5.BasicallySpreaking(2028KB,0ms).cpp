#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int ctod(char c){
    if(c >= '0' && c<='9')
        return c - '0';
    return c - 'A' + 10;
}
char dtoc(int n){
    if(n >= 0 && n <=9)
        return n + '0';
    return n + 'A' - 10;
}

int BaseToDec(string& s, int b){
    int digit = s.size();
    int result =0;
    int pow =1;
    for(int i = digit-1; i>=0; i--){
        result += ctod(s[i]) * pow;
        pow *= b;
    }

    return result;
}

string DecToBase(int n, int b){
    string result = "";
    string empty = "";
    do
    {
        result += dtoc(n%b);
        n /= b;
    } while (n > 0);
    reverse(result.begin(), result.end());
    if(result.size() > 7)
        result = "ERROR";
    for(int i=0;i<7 - result.size();i++){
        empty += " ";
    }
    return empty + result;
}

string BaseConversion(string num, int from, int to){
    return DecToBase(BaseToDec(num, from), to);
}

int main(){
    string num;
    int from, to;
    vector<string> result;
    while(true){
        cin >> num >> from >> to;

        if(cin.eof())
            break;

        result.push_back(BaseConversion(num, from, to));
    }
    for(string a : result){
        cout << a << '\n';
    }
}