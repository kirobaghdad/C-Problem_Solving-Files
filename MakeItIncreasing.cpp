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


int coins(int a, int b) {
	if (a == 0)
		return 1;
	else return (a + 2 * b + 1);
}

int main() {
	int t;
	cin >> t;
	int* ans = new int[t];
	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		ans[i] = coins(a, b);
	}

	printarray(ans, t);

}