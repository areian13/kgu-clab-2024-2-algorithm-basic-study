#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int N, B;
string ans;

char change(int a) {
	return (a - 10) + 'A';
}

void solve(int val) {
	if (val == 0) {
		if (ans == "")
			ans = "0";
		return ;
	}

	if (val / B == 0) {
		ans += val >= 10 ? change(val) : val + '0';
		return ;
	}

	solve(val / B);
	int v = val % B;
	ans += v >= 10 ? change(v) : v + '0';
}

int main() {
	FastIO;
	cin >> N >> B;
	ans = "";
	solve(N);
	cout << ans << "\n";
}