#include <iostream>
using namespace std;

void readArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int* restoring(int* s, int* f, int n) {
	int* durations = new int[n];
	for (int i = 0; i < n; i++) {
		if (!i || (s[i] > f[i - 1]))
		{
			durations[i] = f[i] - s[i];
		}
		else {
			durations[i] = f[i] - f[i - 1];
		}
	}
	return durations;
}


int main() {
	int t;
	cin >> t;
	int n;
	int** ans = new int*[t];
	int* Ns = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> n;
		int* s = new int[n];
		readArray(s, n);
		int* f = new int[n];
		readArray(f, n);

		ans[i] = restoring(s, f, n);
		Ns[i] = n;
		delete[]s;
		delete[]f;
	}
	

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < Ns[i]; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}