#include <iostream>
#include <queue>
using namespace std;
int box[1000][1000];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int M, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> box[i][j];


	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (box[i][j] == 1) q.push({j,i});

	while (!q.empty()) {
		int qx = q.front().first;
		int qy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = qx + dx[i];
			int ty = qy + dy[i];
			if (tx < 0 || tx >= M || ty < 0 || ty >= N) continue;
			if (box[ty][tx] != 0) continue;
			box[ty][tx] = box[qy][qx] + 1;
			q.push({ tx,ty });
		}
	}

	int mx = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (box[i][j] == 0) { cout << "-1"; return 0; }
			else if (box[i][j] != -1) mx = max(mx, box[i][j]);
	if (mx == 1) cout << "0";
	else cout << mx-1;
}