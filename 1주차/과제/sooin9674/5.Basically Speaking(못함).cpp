#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char dtoc(int d){
    if(0<=d && d<=9)
        return d +'0';
    return d - 10 + 'A';
}

int ctod(char c){
    if('0'<=c && c<='9')
        return c - '0';
    return c - 'A' + 10;
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


string DecToBase(int n, int b){
    string result="";
    do{
        result += dtoc(n % b);
        n /= b;
    }while(n>0);
    
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FastIO;

    string number;
    int n, b;

    getline(cin, number);  
    cin >> n >> b;        

    bool isValid = true;

    for(char c : number){
        int digit = ctod(c);
        if(digit >= n){
            isValid = false;
            break;
        }
    }

    if(!isValid){
        cout << "ERROR\n";
        return 0;
    }

    int dec = BaseToDec(number, n);

    string result = DecToBase(dec, b);

    if(result.length() > 7){
        cout << "ERROR\n";
    } else {
        cout << string(7 - result.length(), ' ') << result << endl;
    }

    return 0;
    //error: no input files
}
