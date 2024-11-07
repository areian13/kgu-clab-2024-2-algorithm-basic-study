#include <iostream>
#include <string>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBracket(char c)
{
    return c == '(' || c == ')' || c == '[' || c == ']';
}

bool IsBalanced(string& str)
{
    string bracket = "";
    for (char c : str)
    {
        if (IsBracket(c))
            bracket += c;
    }

    while (!bracket.empty())
    {
        int idx1 = bracket.find("()");
        if (idx1 != string::npos)
            bracket.replace(idx1, 2, "");

        int idx2 = bracket.find("[]");
        if (idx2 != string::npos)
            bracket.replace(idx2, 2, "");

        if (idx1 == string::npos && idx2 == string::npos)
            break;
    }
    return bracket.empty();
}

int main()
{
    FastIO;

    while (true)
    {
        string str;
        getline(cin, str);

        if (str == ".")
            break;

        string result = (IsBalanced(str) ? "yes" : "no");
        cout << result << '\n';
    }
}