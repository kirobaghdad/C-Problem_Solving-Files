#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string time) {
	if (time[0] == time[4] && time[1] == time[3])
		return true;
	else return false;
}

void printarray(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

void increaseTime(string& time, int x) {
	int hours = x / 60;
	int minutes = x % 60;

	int H = (time[1] - 48)  + 10 * (time[0] - 48);
	int M = (time[4] - 48) + 10 * (time[3] - 48);

	//Increasing the Hours part (HH)
	H = (H + hours) % 24;

	//Increasing the Minutes part (MM)
	if (M + minutes >= 60) {
		H = (H + 1) % 24;
	}
	M = (M + minutes) % 60;

	time[1] = (H % 10) + 48;
	time[0] = (H / 10) + 48;

	time[4] = (M % 10) + 48;
	time[3] = (M / 10) + 48;

}

bool notEqual(string time, string orgTime) {
	int HTime = (time[1] - 48) + 10 * (time[0] - 48);
	int MTime = (time[4] - 48) + 10 * (time[3] - 48);

	int HOrg = (orgTime[1] - 48) + 10 * (orgTime[0] - 48);
	int MOrg = (orgTime[4] - 48) + 10 * (orgTime[3] - 48);

	if (HOrg == HTime && MTime == MOrg) {
		return false;
	}
	return true;
}

int theClock(string time, int x) {
	string orgTime = time;
	int count = 0;
	do {
		increaseTime(time, x);
		count += isPalindrome(time);
	} while (notEqual(time, orgTime));
	return count;
}

int main() {
	int t, x;
	cin >> t;
	string time;
	int* ans = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> time;
		cin >> x;
		ans[i] = theClock(time, x);
	}

	printarray(ans, t);
	delete[]ans;
}