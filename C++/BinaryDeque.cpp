#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



//If random = 0 then the pivot is the last element and if random = 0 then pivot is random(Randomized-Partition)
int partition(int*& arr, int p, int r, bool random = 0) {
	int l;
	if (random) {
		l = rand() % (r - p + 1) + p;
		swap(arr[r], arr[l]);
	}
	int x = arr[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (arr[j] <= x) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}


void quickSort(int*& arr, int p, int r) {
	int q;
	if (p < r) {
		q = partition(arr, p, r, 1);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}


void readArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

int arraySum(int* arr, int i0, int j0) {
	int sum = 0;
	for (int i = i0; i <= j0; i++)
		sum += arr[i];
	return sum;
}

int longestSubarray(int* arr, int n, int s) {
	int len = 0;
	vector<int> lengths;

	int l = 0, r = 0;
	while (r < n) {
		if (arraySum(arr, l, r) > s)
		{
			lengths.push_back(r - l);
			while (!arr[l])
				l++;
			l++;
		}
		r++;
	}
	if (arraySum(arr, l, r - 1) == s)
		lengths.push_back(r - l);

	return *max_element(lengths.begin(), lengths.end());
}

//This algo exceeded the time limit
int minNum(int* arr, int n, int s) {	
	int num = 0;
	int sum = 0;

	if (arraySum(arr, 0, n - 1) < s)
		return -1;
	 num = longestSubarray(arr, n, s);

	
	return n - num;
}



int main() {
	int t, n, s;
	cin >> t;
	int* ans = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> n;
		int* arr = new int[n];
		cin >> s;
		readArray(arr, n);
		ans[i] = minNum(arr, n, s);
		delete[]arr;
	}

	printarray(ans, t);
	delete[]ans;
}