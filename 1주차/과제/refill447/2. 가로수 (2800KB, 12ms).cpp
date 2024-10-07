#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int N;
int road[100010];
int dist[100010];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int gcd_many_num() {
	int val = dist[0];
	for (int i = 1; i < N - 1; i++) {
		val = gcd(dist[i], val);
	}
	return val;
}

int main() {
	FastIO;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> road[i];
		if (i > 0)
			dist[i - 1] = road[i] - road[i - 1];
	}

	int val = gcd_many_num();
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans += (dist[i] / val) - 1;
	}
	cout << ans << "\n";
	return 0;
}