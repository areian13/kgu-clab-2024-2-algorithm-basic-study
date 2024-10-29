#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    auto comp = [](const int a, const int b){
        if (abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > b;
    };

    priority_queue<int, vector<int>, decltype(comp)> PQ(comp);
    for(int i =0; i<n; i++){
        int x;
        cin >> x;

        if(x != 0){
            PQ.push(x);
        }
        else{
            if(PQ.empty())
                PQ.push(0);

            cout << PQ.top() << '\n';
            PQ.pop();
        }
    }
}