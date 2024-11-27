#include <bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int n, m;
vector<int> cards;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		cards.push_back(num);
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		cout << binary_search(cards.begin(), cards.end(), num) << ' ';
	}
}

int main() {
	solve();
}