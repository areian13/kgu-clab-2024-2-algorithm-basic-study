#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int N, M;
int g, l;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void lcm(int a, int b) {
	g = gcd(a, b);
	l = a * b / g;
}

int main() {
	FastIO;
	cin >> N >> M;
	int a = N > M ? N : M;	
	int b = N > M ? M : N;
	lcm(a, b);
	cout << g << "\n" << l << "\n";
	return 0;
}