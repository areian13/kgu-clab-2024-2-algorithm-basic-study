#include <iostream>
#include <queue>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> PQ;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (x != 0)
            PQ.push_back(x);
        else
        {
            if (PQ.empty())
                PQ.push_back(0);

            int idx = 0;
            for (int i = 0; i < PQ.size(); i++)
            {
                if (PQ[idx] < PQ[i])
                    idx = i;
            }

            cout << PQ[idx] << '\n';
            PQ.erase(PQ.begin() + idx);
        }
    }
}