#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N,t;
	vector<int> sosu;
	sosu.push_back(2);
	cin >> N;
	for (int i = 3; i <= N; i++) {
		for (auto iter = sosu.begin(); iter != sosu.end(); iter++) {
			t = *iter;
			if (t * t > i) break;
			if (i % t == 0) break;
		}
		if (t * t > i) sosu.push_back(i);
	}
	int start = 0, end = 0, now = 2, res = 0;
	while (end < sosu.size() && start <= end) {
		if (now == N) res++;
		if (now <= N) now += sosu[++end];
		else now -= sosu[start++];
	}

	cout << res;

	return 0;
}