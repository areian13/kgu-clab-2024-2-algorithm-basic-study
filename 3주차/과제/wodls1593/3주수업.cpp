#include <iostream>
#include <set>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;
int main(){

    FastIO;
    int n;
    cin >> n;

    set<string> isExisted;

    for(int i=0; i<n;i++){
        string name, state;
        cin >> name >> state;

        if(state == "enter"){
            isExisted.insert(name);
        }else{
            isExisted.erase(name);
        }
    }

    for(const string& elem : isExisted){
        cout << elem << '\n';
    }

    
}