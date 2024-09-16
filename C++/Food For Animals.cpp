#include <iostream>
using namespace std;


int main() {
	int t;
	int a, b, c, x, y;
	cin >> t;
	int totalFood;
	bool* results = new bool[t];
	for (int i = 0; i < t; i++) {
		cin >> a >> b >> c >> x >> y;
		if (x > a) {
			x = x - a;
			c = c - x;
		}
		if (c < 0)
			results[i] = 0;
		else {
			if (y > b) {
				y = y - b;
				c = c - y;
			}
			if (c < 0)
				results[i] = 0;
			else results[i] = 1;
		}
	}

	for (int i = 0; i < t; i++)
		results[i] ? cout << "YES" << endl : cout << "NO" << endl;
}