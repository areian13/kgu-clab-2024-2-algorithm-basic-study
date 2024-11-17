#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int BS(int x, vector<long long>&a){
    int start = 0, end = a.size() -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(a[mid] < x)
            start = mid + 1;
        else if(a[mid] >= x)
            end = mid -1;
    }
    return end + 1;
}
int BS2(int x, vector<long long>&a){
    int start = 0, end = a.size() -1;

    while(start <= end){
        int mid = (start + end) / 2;

        if(a[mid] <= x)
            start = mid + 1;
        else if(a[mid] > x)
            end = mid -1;
    }
    return end + 1;
}
int BSCheck(int num, vector<long long> &deck, long long n, long long m = 0){
    int result;
    int check;
    int check2;
    switch (num)
    {
    case 1:
        check = BS(n, deck);
        //cout << '\n' << check << ", " << deck.size() << '\n';
        result = deck.size() - check;
        return result;
        break;
    case 2:
        check = BS2(n, deck);
        //cout << '\n' << check << ", " << deck.size() << '\n';
        result = deck.size() - check;
        return result;
        break;
    case 3:
        check = BS(n, deck);
        check2 = BS2(m, deck);
        return check2 - check;
        break;
    default:
        break;
    }
}
// 어디서 예외가 발생한 것 같은데.
int main(){
    FastIO;

    int n, m;
    cin >> n >> m;
    vector<long long> deck(n);

    for (int i = 0; i < n; i++)
    {
        cin >> deck[i];
    }
    sort(deck.begin(), deck.end());

    int num;
    long long checkNum1, checkNum2;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        if(num == 3){
            cin >> checkNum1 >> checkNum2;
            cout << BSCheck(num, deck, checkNum1, checkNum2) << '\n';
        }
        else{
            cin >> checkNum1;
            cout << BSCheck(num, deck, checkNum1) << '\n';
        }
    }
    
    
}
