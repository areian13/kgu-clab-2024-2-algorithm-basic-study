#include <bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<int> arr;
int n, m;

void input() {
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int my_binary_search(int k) {
	int l = 0, r = arr.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] == k) {
			return mid;
		} else if (arr[mid] < k) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	if (l >= n) return n - 1;
	return l;
}


void first() {
	int k; cin >> k;
	int idx = my_binary_search(k);
	while (arr[idx] < k && idx < n) 
		idx++;
	while (arr[idx] == arr[idx - 1])
		idx--;
	cout << n - idx << '\n';
}

void second() {
	int k; cin >> k;
	int idx = my_binary_search(k);
	while (arr[idx] <= k && idx < n) {
		idx++;
	}
	cout << n - idx << '\n';
}

void third() {
	int i, j; cin >> i >> j;
	int idx1 = my_binary_search(i);
	int idx2 = my_binary_search(j);

	// cout << idx1 << ' ' << idx2 << '\n';

	while (arr[idx1] < i && idx1 < n) {
		idx1++;
	}
	while (arr[idx2] > j && idx2 >= 0) {
		idx2--;
	}

	while (arr[idx1] == arr[idx1 - 1])
		idx1--;
	while (arr[idx2] == arr[idx2 + 1])
		idx2++;
	
	if (idx2 - idx1 < 0) cout << 0 << '\n';
	else cout << idx2 - idx1 + 1 << '\n';
}

void solve() {
	while (m--) {
		int cmd;
		cin >> cmd;

		if (cmd == 1) {
			first();
		} 
		else if (cmd == 2) {
			second();
		} 
		else if (cmd == 3) {
			third();
		}
	}
}

int main() {
	FastIO;
	input();
	solve();
}