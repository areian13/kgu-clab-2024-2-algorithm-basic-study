#include <iostream>
#include <stack>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    stack<int> S;
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int x;
            cin >> x;

            S.push(x);
        }
        else if (cmd == "pop")
        {
            if (S.empty())
                S.push(-1);

            cout << S.top() << '\n';
            S.pop();
        }
        else if (cmd == "size")
            cout << S.size() << '\n';
        else if (cmd == "empty")
            cout << S.empty() << '\n';
        else if (cmd == "top")
            cout << (S.empty() ? -1 : S.top()) << '\n';
    }
}