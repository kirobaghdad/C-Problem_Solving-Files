#include <iostream>
using namespace std;


bool makeOdd_Even(int* arr, int n) {
	int x = arr[0] % 2;
	bool y = false;
	for (int i = 2; i < n; i = i + 2) {
		if (x != (arr[i] % 2)) {
			y = true;
			break;
		}
	}
	if (y)
		return false;
	else {
		x = arr[1] % 2;
		for (int i = 3; i < n; i = i + 2) {
			if (x != (arr[i] % 2)) {
				y = true;
				break;
			}
		}
		if (y)
			return false;
		else return true;
	}
}


int main() {

	int t;
	cin >> t;
	int n;
	bool* results = new bool[t];

	for (int i = 0; i < t; i++) {
		cin >> n;
		int* arr = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		results[i] = makeOdd_Even(arr, n);
	}

	for (int i = 0; i < t ; i++) {
		results[i] ? cout << "YES" << endl : cout << "NO" << endl;
	}
}