#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

vector<long long> tree;
vector<long long> arr;
vector<pair<long long, pair<long long, long long>>> karr;
int N, M, K;

long long tree_init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	long long a = tree_init(node * 2, start, mid);
	long long b = tree_init(node * 2 + 1, mid + 1, end);
	return tree[node] = a + b;
}

void update(int node, int start, int end, long long num, int idx) {
	if (idx < start || idx > end)
		return ;

	tree[node] += num;
	if (start == end) return ;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, num, idx);
	update(node * 2 + 1, mid + 1, end, num, idx);
}

long long tree_query(int node, int start, int end, int S, int E) {
	if (S > end || E < start)
		return 0;
	if (S <= start && E >= end)
		return tree[node];

	int mid = (start + end) / 2;
	long long a = tree_query(node * 2, start, mid, S, E);
	long long b = tree_query(node * 2 + 1, mid + 1, end, S, E);
	return a + b;
}

void input() {
	cin >> N >> M >> K;
	arr.push_back(-1);
	for (int i = 0; i < N; i++) {
		long long num; cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < K + M; i++) {
		long long a, b, c; cin >> a >> b >> c;
		karr.push_back(make_pair(a, make_pair(b, c)));
	}
	tree.resize(N * 4, 0);
}

void solve() {
	for (auto i : karr) {
		if (i.first == 1) {
			update(1, 1, N, i.second.second - arr[i.second.first], i.second.first);
			arr[i.second.first] = i.second.second;
		}
		if (i.first == 2)
			cout << tree_query(1, 1, N, i.second.first, i.second.second) << "\n";
	}
}

int main() {
	FastIO;
	input();
	tree_init(1, 1, N);
	solve();
	return 0;
}
