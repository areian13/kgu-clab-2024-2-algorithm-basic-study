#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string ExplodedString(string& str, string& bomb)
{
    int m = bomb.size();

    string result = str;
    while (!result.empty())
    {
        int idx = result.find(bomb);
        if (idx == string::npos)
            break;
        
        result.replace(idx, m, "");
    }
    return result;
}

int main()
{
    FastIO;

    string str, bomb;
    cin >> str >> bomb;

    string result = ExplodedString(str, bomb);
    if (result.empty())
        cout << "FRULA" << '\n';
    else
        cout << result << '\n';
}