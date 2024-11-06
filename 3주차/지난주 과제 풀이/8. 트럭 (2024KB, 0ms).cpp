#include <iostream>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, w, l;
    cin >> n >> w >> l;

    queue<int> Q;
    for (int i = 0; i < w; i++)
        Q.push(0);

    int k = 0; // 현재 총 적재된 무게
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        // Q.front(): 이제 빠질 무게
        // 즉, 현재 적재된 무게에서 빠질거 빠지고, 더할거 더했을 때,
        // 무게가 만약 l보다 크다면 계속 뺀다.
        while (k - Q.front() + t > l)
        {
            k -= Q.front();
            Q.pop();
            Q.push(0);
            result++;
        }

        // 이제 적재 가능한 무게가 되었으니 적재한다.
        k += t - Q.front();
        Q.pop();
        Q.push(t);

        result++;
    }

    // 마지막으로 넣은 트럭이 pop될때까지 while.
    // 단순하게 result += Q.size()나 result += w 해줘도 된다.
    while (!Q.empty())
    {
        result++;
        Q.pop();
    }
    cout << result << '\n';
}