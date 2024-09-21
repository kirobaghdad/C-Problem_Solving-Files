#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double factorial(double n) {
	//cout << 
	double factorial = 1;
	for (double i = 2; i <= n; i++) {
		factorial = factorial * i;
	}
	return factorial;
}

double nCr(double n, double r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
	int q;
	string str1, str2;

	cin >> q;

	double n = 0;
	double* results = new double[q];

	for (int i = 0; i < q; i++)
		results[i] = 1;


	for (int i = 0; i < q; i++) {
		cin >> str1;
		cin >> str2;
		bool allA = true;

		n = 0;

		for (int j = 0; j < str1.length(); j++)
		{
			if (str1[j] != 'a') {
				allA = false;
				continue;
			}
		}
			
		if (allA && str2.length() == 1 && str2 == "a")
			{
				results[i] = 1;
				continue;
			}

			else {
				for (int j = 0; j < str2.length(); j++)
					if (str2[j] == 'a') {
						results[i] = -1;
						break;
					}
				if (results[i] == -1)
					continue;;
				for (int j = 0; j < str1.length(); j++)
					if (str1[j] == 'a')
						n++;
			}
		for (int j = 1; j <= n; j++) {
			results[i] += nCr(n, j);
		}
		
	}
		for (int i = 0; i < q; i++)
			cout << fixed << setprecision(0) << results[i] << endl;

		return 0;
}