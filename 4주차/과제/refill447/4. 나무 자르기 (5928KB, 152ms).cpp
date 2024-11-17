#include <bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int N, M;
int maxLen;
vector<int> tree;

void input() {
    cin >> N >> M;
    tree.resize(N);
    maxLen = 0;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        if (maxLen < tree[i]) maxLen = tree[i];
    }
}

void solve() {
    int start = 0, end = maxLen;
    int res = 0;

    while (start <= end) {
        int mid = (start + end) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (tree[i] > mid) {
                sum += tree[i] - mid;
            }
        }

        if (sum < M) {
            end = mid - 1;
        } else {
            res = mid;
            start = mid + 1;
        }
    }

    cout << res << '\n';
}

int main() {
    FastIO;
    input();
    solve();
}
