#include <bits/stdc++.h>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

/*
	이분 탐색으로 아이디어가 안떠올라서 그냥 구현으로 풀었는데 맞왜틀..
*/

int N, M;
vector<bool> arr;

void input() {
	cin >> N;
	arr.resize(N + 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int idx; cin >> idx;
		arr[idx] = true;
	}
}

void solve() {
	int maxDist = 0;
	int lastIdx = 0;
	bool isStart = false;
	for (int i = 0; i < N + 1; i++) {
		if (arr[i]) {
			int dist = i - lastIdx;
			if (isStart) dist /= 2;
			maxDist = max(dist, maxDist);
			lastIdx = i;
			isStart = true;
		}
		if (i == N && !arr[i]) {
			int dist = N - lastIdx;
			maxDist = max(dist, maxDist);
		}
	}
	cout << maxDist << '\n';
}

int main() {
	FastIO;
	input();
	solve();
}