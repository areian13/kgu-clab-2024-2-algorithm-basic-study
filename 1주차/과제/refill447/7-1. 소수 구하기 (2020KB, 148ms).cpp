#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
using namespace std;

int M, N;

bool check(int a) {
	if (a == 1)
			return false;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

void solve() {
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (!check(i)) continue;
		cout << i << "\n";
	}
}

int main() {
	FastIO;
	solve();
	return 0;
}
