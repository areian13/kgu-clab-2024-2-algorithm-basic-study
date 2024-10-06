#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a%b);
}

int LCM(int a, int b){
    return (a * b) / GCD(a, b);
}
int main(){
    int num1, num2;
    cin >> num1 >> num2;

    cout << GCD(num1, num2) << "\n"; 

    cout << LCM(num1, num2);

}