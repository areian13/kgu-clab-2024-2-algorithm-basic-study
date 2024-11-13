#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    map<string, bool, greater<string>> check;
    string name;
    string inout;
    for(int i=0;i<n;i++){
        cin >> name >> inout;

        check[name] = (inout == "enter");
        
    }
    for(pair<const string, bool>& elem : check){
        if(elem.second)
            cout << elem.first << '\n';
    }

}