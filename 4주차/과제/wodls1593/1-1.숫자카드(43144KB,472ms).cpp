#include <iostream>
#include <unordered_map>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main(){
    FastIO;
    int n, m;
    int checkNum;
    cin >> n;
    int a;
    
    unordered_map<int, bool> numDeck;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        numDeck[a] = true; 
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> checkNum;
        cout << numDeck[checkNum] << " ";
    }

}