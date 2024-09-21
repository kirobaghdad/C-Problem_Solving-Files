#include <iostream>
using namespace std;


void readArray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}


void constructPedestal(int n, int*& second, int* first, int* third, int i) {
	int x = n / 3 - 1;
	int y = n - x * 3;
	
	third[i] = x;
	if (y == 4 || y == 5)
	{
		first[i] = x + 3;
		second[i] = x + (y - 3);
	}
	else
	{ 
		first[i] = x + 2; 
		second[i] = x + 1;
	}
}

int main() {
	int t, n;
	cin >> t;
	int* first = new int[t];
	int* second = new int[t];
	int* third = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> n;
		constructPedestal(n, second, first, third, i);
	}

	for (int i = 0; i < t; i++) {
		cout << second[i] << " " << first[i] << " " << third[i] << endl;
	}

	delete[]first;
	delete[]second;
	delete[]third;
}