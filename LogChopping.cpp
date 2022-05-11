#include <iostream>
#include <string>
using namespace std;


bool canBeConstructed(string& str, string w) {
    bool y;

    if (str.compare(w) == 0) {
        return true;
    }
    else if (w.length() >= str.length()) {
        return false;
    }
    else {
        y =    canBeConstructed(str, w + "aa")
            || canBeConstructed(str, w + "aaa")
            || canBeConstructed(str, w + "bb")
            || canBeConstructed(str, w + "bbb");
        return y;
    }
}

int main() {
    int t;
    cin >> t;
    bool* answers = new bool[t];
    string str;
    string w;
    for (int i = 0; i < t; i++) {
        cin >> str;
         answers[i] = canBeConstructed(str, w);
    }

    for (int i = 0; i < t; i++) {
        answers[i] ? cout << "YES" << endl : cout << "NO" << endl;
    }
}