/*
 * 3. 듣보잡 문제와 완벽히 동일하게 풀 수 있습니다.
 * 해쉬맵, 이분탐색, 정렬 모두 말이죠.
 * 문자열이 숫자가 되어 들어오기도 하고,
 * 입력이 오름차순으로 들어오다보니 이게 더 쉽겠군요.
 */

#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn(int num, vector<int>& cd)
{
    int start = 0;
    int end = cd.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (cd[mid] < num)
            start = mid + 1;
        else if (cd[mid] > num)
            end = mid - 1;
        else
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<int> cds(n);
        for (int i = 0; i < n; i++)
            cin >> cds[i];

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            int cd;
            cin >> cd;

            result += IsIn(cd, cds);
        }
        cout << result << '\n';
    }
}