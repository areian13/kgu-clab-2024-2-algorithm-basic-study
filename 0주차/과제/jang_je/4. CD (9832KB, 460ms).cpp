#define MAX 1000000
#include <iostream>
using namespace std;

int narr[MAX];
int marr[MAX];
int main() {
	while (1) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		int N, M, t;
		cin >> N >> M;
		if (N + M == 0) break;
		for (int i = 0; i < N; i++) {
			cin >> t;
			narr[i] = t;
		}

		for (int i = 0; i < M; i++) {
			cin >> t;
			marr[i] = t;
		}

		int nind = 0, mind = 0, res = 0;
		while (nind != N && mind != M) {
			if (narr[nind] == marr[mind]) {
				res++; nind++; mind++;
			}
			else if (narr[nind] < marr[mind]) nind++;
			else mind++;
		}

		cout << res << "\n";
	}
}