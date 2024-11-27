#include <bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unordered_map<int, bool> isExisted;
int n, m;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		isExisted[num] = true;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (isExisted[num]) cout << 1 << ' ';
		else cout << 0 << ' ';
	}
}
 
int main() {
	FastIO;
	solve();
}