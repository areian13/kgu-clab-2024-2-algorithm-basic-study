#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

long long CountLan(int length, vector<int>& lan){
    long long result = 0;
    for(int l : lan){
        if(l > length)
            result += (l - length);
    }
    return result;
}

long long PS(int n, vector<int>& lan){
    long long start = 1, end = INT_MAX;

    long long result = 0;
    while(start <= end){
        long long mid = (start +end) / 2;

        long long lanCnt = CountLan(mid, lan);
        if(lanCnt < n){
            end = mid - 1;
        }
        else if(lanCnt >= n){
            start = mid + 1;
            result = max(result, mid);
        }
    }
    return result;
}

int main(){
    FastIO;
    int n, m;
    

    cin >> n >> m;
    vector<int> tree(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    
    cout << PS(m, tree) << '\n';
}