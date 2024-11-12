#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main(){
    FastIO;
    int N;
    cin >> N;  
    int x, y;
    int cnt=0;
    vector<int> test;
    unordered_map<int, vector<int>> student;
    for(int i=0; i<N;i++){
        cin >> x >> y;
        test.push_back(x);
        test.push_back(y);
        student[i] = test;
        test.clear();
        cnt++;
    }
    // cout << "========================" << '\n';

    for(pair<int, vector<int>> elem : student){
        // cout << "========================" << '\n';
        // cout << elem.second.front() << ' ' << elem.second.back() << '\n';
        // cout << "========================" << '\n';
        for(pair<int,vector<int>> elem2 : student){
            //cout << elem.second.front()%elem2.second.front() << ' ' << elem.second.back()%elem2.second.back() << '\n';
            if(elem != elem2){
                if(elem.second.front()%elem2.second.front() == 0 && elem.second.back()%elem2.second.back() == 0)
                cnt--;
            }
            
        }
    }
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N; j++){
    //         if(j != i){
    //             if(student[i].front()%student[j].front() == 0 && student[i].back()%student[j].back() == 0)
    //                 cnt--;
    //         }
    //     }
    // }
    cout << cnt << '\n';


}