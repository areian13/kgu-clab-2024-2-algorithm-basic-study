#include <iostream>
#include <cmath>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Submit
{
    int spendTime;
    int spendMemory;
    int codeLength;
    int submitTime;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    auto comp = [](const int a, const int b)
        {
            if (abs(a) == abs(b))
                return a > b;
            return abs(a) > abs(b);
        };

    priority_queue<int, vector<int>, decltype(comp)> absHeap(comp);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != 0)
            absHeap.push(x);
        else
        {
            if (absHeap.empty())
                absHeap.push(0);

            cout << absHeap.top() << '\n';
            absHeap.pop();
        }
    }
}