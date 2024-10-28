#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<char> st;
    char text[100];
    
    while(true){
        
        cin.getline(text, 100, '\n');
        //cout << text[0];
        if(text[0] == '.') break;
        for(char a: text){

            if(a=='.'){
                if(st.empty())
                    cout<<"yes"<<endl;
                else
                    cout<<"no"<<endl;
                st = stack<char>();
                break;
            }
            if(a == '(' || a==')' || a=='[' || a==']'){
                if(a==')'&&!st.empty())
                {
                    if(st.top() == '('){
                        st.pop();
                        continue;
                    }
                }
                if(a==']'&&!st.empty()){
                    if(st.top()=='['){
                        st.pop();
                        continue;
                    }
                    
                }
                    

                st.push(a);
            }    
        }
        
    }
    
}