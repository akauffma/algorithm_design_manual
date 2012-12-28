#include <iostream>
#include <vector>

using namespace std;

bool sumEquals(vector<int> S, int T) {
	int sum = 0;
	for (int i = 0; i < S.size(); ++i)
		sum += S[i];
	return sum == T;
}

bool knapsack(vector<int> S, int T) {
	if (S.size() == 0)
		return false;
	if (sumEquals(S,T))
		return true;

	bool ret = false;
	for (int i = 0; i < S.size(); ++i) {
		vector<int> S_prime = S;
		S_prime.erase(S_prime.begin()+i);
		ret = (ret || knapsack(S_prime,T));
	}

	return ret;
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

	cout << knapsack(S, T) << endl;
	return 0;
}
