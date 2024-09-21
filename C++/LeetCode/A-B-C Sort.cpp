#include <iostream>

using namespace std;


void addToMiddle(int x, int*& b, int n) {
	if (n % 2) {
		if (b[n / 2] == -1) {
			b[n / 2] == x;
			return;
		}
		else {
			int i;
			for (i = 0; i < n; i++) {
				if (b[i] != -1) {

				}
			}
		}
	}
}


bool algorithm(int* arr, int n) {
	int* b = new int[n];
	int* c = new int[n];
	bool x = n % 2;

	for (int i = 0; i < n; i++)
	{
		b[0] = -1;
		c[0] = -1;
	}

	int cCount = 0;
	int bCount = 0;
	//step 1:
	for (int i = n; i > 0; i--) {
		if (bCount % 2 == 1) {

		}
		else {
			addToMiddle(arr[i], b, n);
		}
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

		results[i] = algorithm(arr, n);
	}

}