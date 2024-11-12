#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int testCaseNum;    
    int clothcnt;

    cin >> testCaseNum;
    
    string cloth;
    string wear;
    map<string, string> testCase;
    for(int i=0; i< testCaseNum;i++){
        cin >> clothcnt;
        for(int j=0; j<clothcnt;j++){
            cin >>cloth >> wear;
            testCase.insert(cloth, wear);
        }
        for(pair<string,string> elem : testCase){
            
        }
        testCase.clear();
    }



}