#include <iostream>
using namespace std;



//Incomplete

void sort(int* arr, int n) {
	int min;
	int minIndex;
	for (int i = 0; i < n; i++) {
		min = arr[i];
		minIndex = i;
		for (int j = i; j < n; j++) {
			if (arr[j] < min)
			{
				min = arr[j];
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}


int getDistinct(int* arr, int n) {
	int distinctNum = 0;
	int i = 0;
	int num;
	while (i < n) {
		num = arr[i];
		while (i + 1 < n && arr[i + 1] == num) {
			i++;
		}
		distinctNum++;
		i++;
	}
	return distinctNum;
}



int allDistinct(int* arr, int n){
	int count = 0;
	sort(arr, n);
	int i = 0;
	int distinctNum = 0;
	
	distinctNum = getDistinct(arr, n);
		count = (n - distinctNum) % 2 == 0 ? distinctNum : distinctNum - 1;
	return count;
}

void printArray(int* arr, int num) {
	cout << "[  ";
	for (int i = 0; i < num; i++)
	{
		if (i > 0)
			cout << ",  ";
		cout << arr[i] << "  ";
	}

	cout << "]" << endl;

}

void readArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

int main() {
	int t, n;
	cin >> t;
	int* ans = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> n;
		int* arr = new int[n];
		readArray(arr, n);
		ans[i] = allDistinct(arr, n);
		delete[]arr;
	}

	printarray(ans, n);
	delete[]ans;
}