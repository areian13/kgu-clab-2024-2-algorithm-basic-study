#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MAXNUM 1'000'000
using namespace std;

int M, N;
bool primeNum[MAXNUM + 10];

void init() {
	// memset(primeNum, true, sizeof(primeNum));
	for (int i = 0; i < MAXNUM + 10; i++)
		primeNum[i] = true;

	primeNum[0] = false;
	primeNum[1] = false;
	for (int i = 2; i * i <= MAXNUM; i++) {
		if (primeNum[i]) {
			for (int j = i * i; j <= MAXNUM; j += i) {
				primeNum[j] = false;
			}
		}
	}
}

void solve() {
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (primeNum[i])
			cout << i << "\n";
	}
}

int main() {
	FastIO;
	init();
	solve();
	return 0;
}
