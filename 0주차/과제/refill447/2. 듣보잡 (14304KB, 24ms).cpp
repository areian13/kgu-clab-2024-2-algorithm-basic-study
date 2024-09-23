#include <bits/stdc++.h>
#define FastIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int N, M;

struct cmp {
    bool operator()(const string& a, const string& b) {
        return a > b; // 오름차
    }
};

struct Trie {
	Trie *alpha[26];
	bool end;
	Trie() {
		for (int i = 0; i < 26; i++)
			alpha[i] = nullptr;
		end = false;
	}

	~Trie() {
		for (int i = 0; i < 26; i++) {
			if (alpha[i])
				delete alpha[i];		
		}
		delete this;
	}
};

priority_queue<string, vector<string>, cmp> pq;
Trie *root;

int main() {
	FastIO;
	cin >> N >> M;

	root = new Trie();
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		Trie *tmp = root;
		for (char i : s) {
			if (tmp->alpha[i - 'a'])
				tmp = tmp->alpha[i - 'a'];
			else {
				tmp->alpha[i - 'a'] = new Trie();
				tmp = tmp->alpha[i - 'a'];
			}
		}
		tmp->end = true;
	}

	for (int i = 0; i < M; i++) {
		string s; cin >> s;
		Trie *tmp = root;
		bool flag = true;

		for (char c : s) {
			if (!tmp->alpha[c - 'a']) {
				flag = false;
				break;
			}
			tmp = tmp->alpha[c - 'a'];
		}
		if (tmp->end && flag)
			pq.push(s);
	}
	
	cout << pq.size() << "\n";
	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	return 0;
}
