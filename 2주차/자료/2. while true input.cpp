#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        // ctrl + Z 입력 시 동작
        if (cin.eof())
            break;

        cout << "I want to go home." << '\n';
    }
}