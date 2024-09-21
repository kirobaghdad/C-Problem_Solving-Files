#include <iostream>
using namespace std;

template <class T>
void readArray(T* arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			cout << 0 << endl;
		else cout << arr[i] << endl;
	}
}
int countB(char* arr, int i, int j) {
	int count = 0;
	for (int l = i; l <= j; l++)
		if (arr[l] == 'B')
			count++;
	return count;
}

int getMax(int* arr, int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int minNum(char* arr, int n, int k) {
	int i = 0, j = k - 1;
	int* min = new int[n];
	for (i = 0; i < n; i++)
		min[i] = -1;

	for (i = 0; j < n; i++) {
		if (!i) {
			min[i] = countB(arr, i, j);
		}
		else {
			min[i] = min[i - 1] - (arr[i - 1] == 'B' ? 1 : 0) + (arr[j] == 'B' ? 1 : 0);
		}
		j++;
	}

	return k - getMax(min, n);
	//int i = 0, j = 0;
	//int maxLen = 0;

	//for (i = 0; i < n; i++) {
	//	if (arr[i] == 'B') {
	//		j = i;
	//		j++;
	//		while (j + 1 < n && arr[j + 1] == 'B')
	//			j++;
	//		if (j - i + 1 > maxLen)
	//			maxLen = j - i + 1;
	//		i = j;
	//	}
	//}

	//return k - maxLen;
	/*if (maxLen > k)
		return 0;
	else if (k > maxLen)
		return k - maxLen;*/
	
}


int main() {
	int t;
	cin >> t;
	int* ans = new int[t];
	int n, k;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> k;
		char* arr = new char[n];
		readArray(arr, n);
		ans[i] = minNum(arr, n, k);
	}


	printarray(ans, t);
}