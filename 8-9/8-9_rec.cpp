#include <iostream>
#include <vector>

using namespace std;

bool knapsack(vector<int> S, int T) {
	if (S.size() == 0) {
		if (T == 0)
			return true;
		return false;
	}
	vector<int> S_prime = S;
	S_prime.erase(S_prime.end()-1);
	return knapsack(S_prime, T-S.back()) || knapsack(S_prime, T);
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
	cout << (knapsack(S, T) ? "True" : "False")  << endl;
	return 0;
}
