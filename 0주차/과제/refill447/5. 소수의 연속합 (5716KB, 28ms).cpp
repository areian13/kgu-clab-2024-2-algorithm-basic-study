#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

vector<bool> isPrime;
vector<int> primeIdx;
int N;
int cnt;

void init() {
	cnt = 0;
	cin >> N;
	isPrime.resize(N + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			primeIdx.push_back(i);
	}
}

void solve() {
	if (N == 2) {
		cout << 1 << "\n";
		return;
	}

	int s = 0;
	int e = primeIdx.size() - 1;
	while (s < e) {
		int sum1 = 0;
		int sum2 = 0;
		
		int i = s;
		int j = e;
		while (i <= e && j >= s) {
			if (sum1 > N && sum2 > N)
				break;
			
			if (sum1 == N)
				cnt++;
			if (sum2 == N) 
				cnt++;

			sum1 += primeIdx[i++];
			sum2 += primeIdx[j--];
		}
		s++;
		e--;
	}

	cout << cnt << "\n";
}

int main() {
	FastIO;
	init();
	solve();
	return 0;
}