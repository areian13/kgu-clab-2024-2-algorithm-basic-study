#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int M, N;

bool check(int a) {
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

void solve() {
	cin >> M >> N;
	int first = -1;
	int ans = 0;

	for (int i = M; i <= N; i++) {
		if (i == 1)
			continue;
		if (check(i)) {
			ans += i;
			if (first == -1)
				first = i;
		}
	}

	if (first == -1) {
		cout << -1 << "\n";
		return ;
	}
	cout << ans << "\n";
	cout << first << "\n";
}

int main() {
	FastIO;
	solve();
	return 0;
}