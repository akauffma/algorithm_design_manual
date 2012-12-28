#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C(int amount, vector<int> denoms) {
	if (amount == 0) 
		return 1;
	if (denoms.size() == 0)
		return 0;
	if (amount < 0)
		return 0;

	vector< vector<int> > changes(denoms.size()+1, vector<int> (amount+1, 0));

	for (int i = 0; i < denoms.size()+1; ++i)
		changes[i][0] = 1;

	for (int i = 1; i < denoms.size()+1; ++i) {
		for (int j = 1; j < amount+1; ++j) {
			int temp = 0;
			temp += (j - denoms[i-1] < 0 ? 0 : changes[i][j-denoms[i-1]]);
			temp += changes[i-1][j];
			changes[i][j] = temp;
		}
	}

	return changes[denoms.size()][amount];
}

int main() {
	cout << "Enter # denominations: " ;
	int numDenoms;
	cin >> numDenoms;

	cout << "Enter denominations: " ;
	vector<int> denoms (numDenoms);
	for (int i = 0; i < numDenoms; ++i)
		cin >> denoms[i];

	cout << "Enter amount: " ;
	int amount;
	cin >> amount;

	cout << "Number of ways to change: " << C(amount, denoms) << endl;
	return 0;
}
