#include <iostream>
#include <string>
using namespace std;


int main() {
	int t;
	cin >> t;

	int x;

	int* results = new int[t];
	for (int i = 0; i < t; i++)
	{
		cin >> x;
		if (x >= 1900) {
			results[i] = 1;
		}
		else if (x >= 1600 && x <= 1899) {
			results[i] = 2;
		}
		else if (x >= 1400 && x <= 1599) {
			results[i] = 3;
		}
		else results[i] = 4;
	}

	for (int i = 0; i < t; i++) {
		if (results[i] == 1)
			cout << "Division 1" << endl;
		else if (results[i] == 2) {
			cout << "Division 2" << endl;
		}
		else if (results[i] == 3) {
			cout << "Division 3" << endl;
		}
		else cout << "Division 4" << endl;
	}
}