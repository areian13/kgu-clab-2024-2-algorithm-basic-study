#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

class Abs
{
    public:
        int x;
        Abs(int x){
            this->x = x;
        }

        friend bool operator<(const Abs& a, const Abs& b){
            if(abs(a.x) != abs(b.x))
                return abs(a.x) > abs(b.x);
            return a.x > b.x;
        }
};

int main(){
    int n;
    cin >> n;

    priority_queue<Abs> PQ;
    for(int i =0; i<n; i++){
        int x;
        cin >> x;

        if(x != 0){
            PQ.push(Abs(x));
        }
        else{
            if(PQ.empty())
                PQ.push(Abs(0));

            cout << PQ.top().x << '\n';
            PQ.pop();
        }
    }
}