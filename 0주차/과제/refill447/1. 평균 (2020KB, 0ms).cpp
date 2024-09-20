#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;

	int maxNum = 0;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		maxNum = max(num, maxNum);
		v.push_back(num);
	}

	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (double)v[i] / maxNum * 100;
	}

	cout << sum / v.size();
	return 0;
}
