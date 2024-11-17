#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


// 매개 변수 탐색 -> 가로등이 많아지면 높이가 낮아진다
int main(){
    FastIO;

    int n, m;
    cin >> n;
    cin >> m;

    int insert;
    vector<int> interval;
    cin >> insert;
    interval.emplace_back(insert);
    while(!cin.eof()){
        cin >> insert;
        for(int a : interval){
            interval.emplace_back(((insert - a) % 2 ==0) ? (insert - a) / 2 : ((insert - a) / 2) + 1);
        }
        
    }
    interval.emplace_back(n - insert);
    
    cout << *max_element(interval.begin(), interval.end()) <<  '\n';
}