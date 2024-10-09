#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

string str;
int N;

bool my_is_digit(char c) {
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

void solve() {
	long long ans = 0;
	long long B = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		long long c;
		if (!my_is_digit(str[i]))
			c = str[i] - 'A' + 10;
		else
			c = str[i] - '0';
			
		ans += c * B;
		B *= N;
	}
	cout << ans << "\n";
}

int main() {
	FastIO;
	cin >> str >> N;
	solve();
	return 0;
}