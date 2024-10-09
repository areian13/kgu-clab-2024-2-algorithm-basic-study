#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    unordered_map<string, bool> isNoHear;
    for (int i = 0; i < n; i++)
    {
        string noHear;
        cin >> noHear;

        isNoHear[noHear] = true;
    }

    vector<string> result;
    for (int i = 0; i < m; i++)
    {
        string noSee;
        cin >> noSee;

        if (isNoHear[noSee])
            result.push_back(noSee);
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (string& noHearSee : result)
        cout << noHearSee << '\n';
}