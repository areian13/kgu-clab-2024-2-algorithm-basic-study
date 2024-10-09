#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int M, N;
bool primeNum[10010];

void init() {
	// memset(primeNum, true, sizeof(primeNum));
	for (int i = 0; i < 10010; i++)
		primeNum[i] = true;

	primeNum[0] = false;
	primeNum[1] = false;
	for (int i = 2; i * i <= 10000; i++) {
		if (primeNum[i]) {
			for (int j = i * i; j <= 10000; j += i) {
				primeNum[j] = false;
			}
		}
	}
}

void solve() {
	cin >> M >> N;
	int first = -1;
	int ans = 0;

	for (int i = M; i <= N; i++) {
		if (primeNum[i]) {
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
	init();
	solve();
	return 0;
}