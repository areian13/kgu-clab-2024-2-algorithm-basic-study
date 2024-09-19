#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
unordered_set<string> dms;
vector<string> dbj;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	string name;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		dms.insert(name);
	}

	for (int i = 0; i < M; i++) {
		cin >> name;
		if (dms.find(name) != dms.end()) dbj.push_back(name);
	}
	
	sort(dbj.begin(), dbj.end());
	cout << dbj.size() << "\n";
	for (auto iter = dbj.begin(); iter != dbj.end(); iter++)
		cout << *iter << "\n";
}