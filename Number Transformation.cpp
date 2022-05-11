#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	int x, y;
	float div;
	int a, b;

	string* str = new string[t];
	for (int i = 0; i < t; i++) {
		a = 1, b = 2;

		cin >> x >> y;
		if (x > y) {
			str[i] = "0 0";
		}
		else if (x == y)
			str[i] = "1 1";
		else
		{
			div = y / (x +0.0);
			if (div != y / x) {
				str[i] = "0 0";
			}
			else {
				bool flag = false;
				int temp = x;
				for (; ; b++) {
					if (flag)
						break;
					for (a = 1; ; a++) {
						x *= b;
						
						if (x == y) {
							str[i] = to_string(a) + ' ' + to_string(b);
							flag = 1;
							break;
						}
						else if (x > y) {
							x = temp;
							break;
						}
					}
				}
			}
		}
	}


	for (int i = 0; i < t; i++)
		cout << str[i] << endl;
}