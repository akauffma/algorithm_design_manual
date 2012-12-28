#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int sortfn (int i, int j) { return (i>j); }

int C(int amount, vector<int> denoms) {
	if (amount == 0)
		return 1;
	if (amount < 0) 
		return 0;
	if (denoms.size() == 0)
		return 0;	
	vector<int> denoms_removed = denoms;
//	denoms_removed.erase(denoms_removed.begin());
//	return C(amount-denoms[0],denoms) + C(amount,denoms_removed);
	denoms_removed.erase(denoms_removed.end()-1);
	return C(amount-denoms.back(), denoms) + C(amount, denoms_removed);


}


int main() {
	cout << "Enter # denominations: " ;
	int numDenoms;
	cin >> numDenoms;

	cout << "Enter denominations: " ;
	vector<int> denoms (numDenoms);
	for (int i = 0; i < numDenoms; ++i)
		cin >> denoms[i];
	sort (denoms.begin(), denoms.end(), sortfn);

	cout << "Enter amount: " ;
	int amount;
	cin >> amount;

	cout << "Number of ways to change: " << C(amount, denoms) << endl;
	return 0;
}
