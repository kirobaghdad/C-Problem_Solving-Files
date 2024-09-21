#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
void printarray(T* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
			cout << 0 << endl;
		else cout <<std::fixed<<setprecision(0)<< arr[i] << endl;
	}
}

int getHorizontalSum(int m)
{
	int sum = 0;
	for (int i = 1; i <= m; i++)
		sum += i;
	return sum;
}

int getVerticalSum(int n, int m) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += m * i;
	}
	return sum;
}

double optimalPath(int n, int m){
	double sum1 = ((m + 0.0) / 2) * (1 + m);
	double sum2 = ((n + 0.0) / 2) * (m + m * n);
	return sum1 + sum2 - m;
}


int main() {
	int t;
	cin >> t;
	int n, m;
	long double* ans = new long double[t];

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		ans[i] = optimalPath(n, m);
	}

	printarray(ans, t);

}