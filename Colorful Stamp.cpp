#include <iostream>
#include <string>
using namespace std;


bool canBeMade(string str) {

	int r = 0, b = 0;
	for (int i = 0; i < str.length(); i++) {
		r = 0;
		b = 0;
		if (str[i] != 'W') {
			while (i < str.length() && str[i] != 'W') {
				if (str[i] == 'B')
					b++;
				else r++;
				i++;
			}

			if (r == 0 || b == 0) {
				return 0;
			}
		}
	}
	return true;
}


//if (!(str[i] == 'W'))
//{
//	if ((hasManyLetters == '0')) {
//		hasManyLetters = str[i];
//	}
//	else if (!(hasManyLetters == str[i])) {
//
//	}
//}
int main() {

	int t;
	cin >> t;
	int n;
	bool* results = new bool[t];
	string str;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> str;
		results[i] = canBeMade(str);
		
	}

	for (int i = 0; i < t; i++) {
		results[i] ? cout << "YES" << endl : cout << "NO" << endl;
	}
}