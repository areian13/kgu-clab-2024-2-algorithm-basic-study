#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> st;     
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string x;
        int num;
        cin >> x;
        if(x == "push"){
            cin >> num;
            st.push(num);
        }
        else if (x == "pop")
        {
            if(st.empty())
                st.push(-1);
            cout << st.top() << endl;
            st.pop();
        }
        else if(x == "size"){
            cout << st.size() << endl;
        }
        else if(x == "empty")
        {
            if(st.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if(x == "top"){
            if(st.empty())
            {
                cout << -1 << endl;
                continue;
            }
            cout << st.top() << endl;
        }
        
    }

}