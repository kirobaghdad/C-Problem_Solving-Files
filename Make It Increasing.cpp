#include <iostream>
using namespace std;

bool isIncreasing(int* arr, int n) {
	for (int i = 0; i < n - 1; i++)
		if (arr[i] >= arr[i + 1])
			return false;
	return true;
}
int makeItIncreasing(int*& arr, int n) {
	int num = 0;
	while(!isIncreasing(arr, n))
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] >= arr[i + 1]) {
			if(arr[i + 1] == 1)
			return -1;
			else
			{
				while (arr[i] >= arr[i + 1]) {
					arr[i] = arr[i] / 2;
					num++;
				}
			}
		}
	}
	return num;
}
int main() {
	int t;
	cin >> t;
	int n;

	int* results = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> n;
		int* arr = new int[n];
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		results[i] = makeItIncreasing(arr, n);
		delete[] arr;
	}

	for (int i = 0; i < t; i++) {
		cout << results[i] << endl;
	}
}