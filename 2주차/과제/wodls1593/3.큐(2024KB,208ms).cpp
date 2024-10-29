#include <iostream>
#include <queue>

using namespace std;

int main(){

    queue<int> q;     
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string x;
        int num;
        cin >> x;
        if(x == "push"){
            cin >> num;
            q.push(num);
        }
        else if (x == "pop")
        {
            if(q.empty())
                q.push(-1);
            cout << q.front() << endl;
            q.pop();
        }
        else if(x == "size"){
            cout << q.size() << endl;
        }
        else if(x == "empty")
        {
            if(q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if(x == "front"){
            if(q.empty())
            {
                cout << -1 << endl;
                continue;
            }
            cout << q.front() << endl;
        }
        else if(x == "back"){
            if(q.empty())
            {
                cout << -1 << endl;
                continue;
            }
            cout << q.back() << endl;
        }
        
    }

}