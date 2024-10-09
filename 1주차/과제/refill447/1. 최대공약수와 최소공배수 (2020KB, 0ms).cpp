#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int N, M;
int g, l;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	FastIO;
	cin >> N >> M;
	cout << gcd(N, M) << "\n" << lcm(N, M) << "\n";
	return 0;
}