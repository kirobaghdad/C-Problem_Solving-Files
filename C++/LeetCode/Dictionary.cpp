#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	string str;
	int index;
	int* results = new int[t];
	for (int i = 0; i < t; i++) {
		index = 0;
		cin >> str;
		if (str[0] > str[1])
			index = 1;
		results[i] = (str[0] - 'a') * 25 + (str[1] - 'a') + index;;
	}

	for (int i = 0; i < t; i++)
		cout << results[i] << endl;
}