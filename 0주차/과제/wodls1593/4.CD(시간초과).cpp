#include <iostream>
#include <set>
#include <map>

int main(){

    using namespace std;


    int N, M;

    int num;
    int cnt = 0;
    set<int> Nset;
    set<int> Mset;

    while(true){
        if(cnt == 0)
            cin >> N >> M;
        if(N == 0 && M ==0) break;
        
        cin >> num;
        
        if(cnt<N)
            Nset.insert(num);
        else
            Mset.insert(num);

        cnt++;
        // cout << "=====" << endl;
        // cout << cnt << endl;
        // cout << N + M << endl;
        // cout << "=====" << endl;

        if(cnt == N + M){
            cnt =0;
            for(int a : Mset){
                if(Nset.find(a) != Nset.end())
                {
                    cnt++;
                }
            }
            cout << cnt << endl;
            cnt =0;
        }
        
    }
    

    return 0;

}