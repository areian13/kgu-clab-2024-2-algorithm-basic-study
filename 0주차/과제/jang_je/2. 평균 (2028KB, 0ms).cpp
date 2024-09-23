#include <iostream>
using namespace std;
double subject[1000];
int main() {
	int N;
	double mx = 0,sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> subject[i];

	for (int i = 0; i < N; i++)	
		if (subject[i] > mx) mx = subject[i];

	for (int i = 0; i < N; i++)
		subject[i] = subject[i] / mx * 100;

	for (int i = 0; i < N; i++)
		sum += subject[i];

	cout << sum / N;
}