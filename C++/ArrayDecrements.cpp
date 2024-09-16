#include <iostream>
using namespace std;
int hasOneUniqueNum(int* arr, int n) {
	int num = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0 && arr[i] > INT_MIN)
			return -1;
		if (arr[i] != INT_MIN) {
			if (num == INT_MIN)
				num = arr[i];
			else if (arr[i] != num)
				return -1;
		}
	}
	return num;
}
bool arrayDecrements(int* arrA, int* arrB, int n) {
	int* differences = new int[n];
	for (int i = 0; i < n; i++) {
		if (arrB[i]) {
			differences[i] = arrA[i] - arrB[i];
		}
		else
			differences[i] = INT_MIN;
	}

	int x = hasOneUniqueNum(differences, n);
	if (x == -1)
		return false;
	else if (x == INT_MIN)
		return true;
	else
	{
		for (int i = 0; i < n; i++) {
			if (!arrB[i] && x < (arrA[i] - arrB[i]))
				return false;
		}
	}
	delete[]differences;
	return true;
}

int main() {
	int t;
	cin >> t;
	bool* ans = new bool[t];

	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int* arrA = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arrA[j];
		}
		int* arrB = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arrB[j];
		}

		ans[i] = arrayDecrements(arrA, arrB, n);
		delete[]arrA;
		delete[]arrB;

	}

	for (int i = 0; i < t; i++) {
		if (ans[i])
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	delete[]ans;
}