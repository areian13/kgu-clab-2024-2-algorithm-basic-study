#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string ExplodedString(string& str, string& bomb)
{
    int m = bomb.size();

    string result = "";
    for (char c : str)
    {
        result += c;

        // 만약 result의 마지막 단어가 bomb과 같다면
        if (result.size() >= m && result.substr(result.size() - m) == bomb) 
            result.resize(result.size() - m); // m만큼 날려버려라
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