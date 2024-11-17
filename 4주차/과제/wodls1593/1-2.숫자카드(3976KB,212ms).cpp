#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

bool BS(int x, vector<int> &a){
    int startNum = 0;
    int endNum = a.size() - 1;
    // -10 2 3 6 10
    while(startNum <= endNum){
        int n = (startNum + endNum) / 2;
        if(a[n] == x) return true;
        if(a[n] > x)
            endNum = n - 1;
        else if(a[n] < x)
            startNum = n + 1;
    }
    return false;
}

int main(){
    FastIO;
    int m, n;
    cin >> n;
    vector<int> numDeck(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numDeck[i];
    }
    sort(numDeck.begin(), numDeck.end());
    // for(int a : numDeck)
    //     cout << a;
    
    cin >> m;
    int checkNum;
    for (int i = 0; i < m; i++)
    {
        cin >> checkNum;
        cout << BS(checkNum, numDeck) << " ";
    }
    
    
}