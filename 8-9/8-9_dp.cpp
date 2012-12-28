#include <iostream>
#include <vector>

using namespace std;

bool knapsack(vector<int> S, int T) {
	vector< vector<bool> > v (S.size()+1, vector<bool> (T+1, false));

	for (int i = 0; i < S.size()+1; ++i)
		v[i][0] = true; 

	for (int i = 1; i < T+1; ++i)
		v[0][i] = false;

	for (int i = 1; i < S.size()+1; ++i) {
		for (int j = 1; j < T+1; ++j)
			if (j-S[i-1] < 0)
				v[i][j] = v[i-1][j];
			else
				v[i][j] = v[i-1][j-S[i-1]] || v[i-1][j];
	}

	for (int i = 0; i < S.size()+1; ++i) {
		for (int j = 0; j < T+1; ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}

	return v[S.size()][T];
}

int main() {
	cout << "Enter T: ";
	int T;
	cin >> T;

	cout << "Enter # items: " ;
	int n;
	cin >> n;

	cout << "Enter knapsack: " ;
	vector<int> S (n);
	for (int i = 0; i < n; ++i) 
		cin >> S[i];


	cout << (knapsack(S,T) == 1 ? "True" : "False") << endl;

	return 0;
}
