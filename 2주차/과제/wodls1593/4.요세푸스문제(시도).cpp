#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    queue<int> q;
    queue<int> q2;
    for(int i=1;i<=N;i++)
        q.push(i);

    int cnt=1;
    int cnt2=1;
    while(true){
        if(q.empty())
            break;  
        if(cnt>N)
        {
            cnt = 1;
        }
        q.pop();
        if(cnt2==K){
            q2.push(cnt);
            cnt2=1;
            cnt++;
            continue;
        }
        q.push(cnt);
        cnt++;
        cnt2++;
        
    }

    for(int i=0; i<N;i++){
        cout << q2.front() << endl;
        cout << "size : " << q2.size() << endl;
        q2.pop();
    }
}
