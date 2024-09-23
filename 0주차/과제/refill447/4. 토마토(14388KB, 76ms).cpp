#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int N, M;
int box[1010][1010];
vector<pair<int, int>> startPoint;
queue<pair<int, int>> qu;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				startPoint.push_back({i, j});
		}
	}
}

void bfs() {
	for (auto i : startPoint)
		qu.push({i.first, i.second});

	while(!qu.empty()) {
		int y = qu.front().first;
		int x = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (box[ny][nx] == -1) continue;
			if (box[ny][nx] == 0) {
				qu.push({ny, nx});
				box[ny][nx] = box[y][x] + 1;
			}
			if (box[ny][nx] > box[y][x] + 1) {
				qu.push({ny, nx});
				box[ny][nx] = box[y][x] + 1;
			}
		}
	}
}

void solve() {
	int maxNum = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (box[i][j] == -1)
				continue;

			if (box[i][j] == 0) {
				cout << -1 << '\n';
				return ;
			}

			maxNum = max(maxNum, box[i][j]);
		}
	}
	cout << maxNum - 1 << '\n';
}

int main() {
	FastIO;
	input();
	bfs();
	solve();
	return 0;
}
