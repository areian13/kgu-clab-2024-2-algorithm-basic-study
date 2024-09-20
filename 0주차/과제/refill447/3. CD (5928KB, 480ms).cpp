#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MAXI 1000000

using namespace std;

/*
입출력이 너무 헷갈렸던 문제
-> 테케가 여러개여서 0 0 이 나올 때까지 프로그램 종료 X
*/

int N, M;
int S;
int E;
int cnt;

int cd[MAXI + 10];
int curNum;

void binary(int start, int end, int num) {
	if (start >= end) 
		return;
	
	int mid = (start + end) / 2;
	if (cd[mid] == num) {
		cnt++;
		S = mid;
	}
	else if (cd[mid] < num) 
		binary(mid + 1, end, num);
	else 
		binary(start, mid, num);
}

int solve() {
	memset(cd, 0, sizeof(cd));
	curNum = 0;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		cd[curNum++] = num;
	}

	S = cnt = 0;
	E = N;
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		binary(S, E, num);
	}

	printf("%d\n", cnt);
	int zz[2]; cin >> zz[0] >> zz[1];
	if (zz[0] == 0 && zz[1] == 0)
		return 0;
	N = zz[0];
	M = zz[1];
	return 1;
}

int main() {
	FastIO;
	cin >> N >> M;
	while (solve()) {;}
	return 0;
}