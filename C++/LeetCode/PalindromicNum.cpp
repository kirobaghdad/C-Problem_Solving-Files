#include <iostream>
using namespace std;

template<class T>
void printarray(T* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			cout << 0 << endl;
		else cout << arr[i] << endl;
	}
}

int getNumOfDigits(int num) {
	int n = 0;
	while (num) {
		num /= 10;
		n++;
	}
	return n;
}

bool isPaliindrome(int num) {
	int n = getNumOfDigits(num);
	int* digits = new int[n];
	int i = n - 1;
	while (num) {
		digits[i--] = num % 10;
		num /= 10;
	}

	for (i = 0; i < n / 2; i++) {
		if (digits[i] != digits[n - i - 1])
			return false;
	}

	delete[]digits;
	return true;
}


long double palindromicNum(long double n, long double num) {
		long double x = 0;
		long double i = 0;
	if ((int)(num / pow(10, n - 1)) != 9) {
		while (i < n) {
			x += 9 * pow(10, i);
			i++;
		}
	}
	else {
		if (n == 2)
			x = 111;
		else
			x += 11 + 11 * pow(10, n - 1);
	}

	return x - num;
	/*int orgNum = num;
	do {
		num += 1;
	} while (!isPaliindrome(num) || (getNumOfDigits(num- orgNum) != n));

	return num - orgNum;*/

}

int main() {
	int t;
	cin >> t;
	long double* ans = new long double[t];
	long double n, num;

	for (int i = 0; i < t; i++) {
		cin >> n >> num;
		ans[i] = palindromicNum(n, num);
	}

	printarray(ans, t);
	delete[]ans;


}