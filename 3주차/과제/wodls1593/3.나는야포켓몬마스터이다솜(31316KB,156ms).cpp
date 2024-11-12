#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main(){
    FastIO;
    
    int cnt;
    int testnum;
    string poketName;
    
    unordered_map<string, string> poketmon;
    unordered_map<string, string> poketmon2;

    string answer;
        
    cin >> cnt >> testnum;
    for(int i=1;i<=cnt;i++){
        cin >> poketName;
        poketmon[to_string(i)] = poketName;
        poketmon2[poketName] = to_string(i);
    }
    for(int i=0;i<testnum;i++){
        cin >> answer;
        
        if(poketmon.find(answer) != poketmon.end()){
            cout << poketmon[answer] << '\n';
        }
        else{
            cout << poketmon2[answer] << '\n';
        }
        // for(pair<string, string> elem : poketmon){
        //     if(answer == elem.first) cout << elem.second << '\n';
        //     else if(answer ==elem.second) cout << elem.first << '\n';
        // }
    }
    
    
}