#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)//최대공약수
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> positions(n);
    for(int i = 0; i < n; i++){
        cin >> positions[i];
    }

    vector<int> gaps(n-1);
    for(int i = 1; i < n; i++){
        gaps[i-1] = positions[i] - positions[i-1];
    }

    int gap_gcd_value = gaps[0];
    for(int i = 1; i < gaps.size(); i++){
        gap_gcd_value = GCD(gap_gcd_value, gaps[i]);
    }

    int total_trees = 0;
    for(int gap : gaps){
        total_trees += (gap / gap_gcd_value) -1;
    }
    
    cout << total_trees << "\n";
    return 0;
}