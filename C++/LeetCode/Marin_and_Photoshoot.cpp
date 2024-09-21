#include <iostream>
#include <string>
using namespace std;

int makeBeautiful(string& S) {
    int ans = 0;
    int num = S.length();

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '0') {
            if (i + 2 < num) {
                if (S[i + 1] == '0')
                    ans +=2;
                else if (S[i + 2] == '0')
                    ans++;
            }
            else if (i + 1 < num) {
                if (S[i + 1] == '0')
                    ans += 2;
            }
        }
    }

    return ans;
}



int main() {
    int t;
    cin >> t;
    int n = 0;
    string S;
    int* arr = new int[t];
    int result;

    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> S;
        result = makeBeautiful(S);
        arr[i] = result;
    }

    for (int i = 0; i < t; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}