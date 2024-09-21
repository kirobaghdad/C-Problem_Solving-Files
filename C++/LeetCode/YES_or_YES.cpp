#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

// naming var in ps
int main()
{
    int t;
    cin >> t;
    string str;
    bool *ans = new bool[t];

    for (int i = 0; i < t; i++)
    {
        cin >> str;
        ans[i] = ((str[0] == 'Y' || str[0] == 'y') && (str[1] == 'e' || str[1] == 'E') && (str[2] == 's' || str[2] == 'S'));
    }

    for (int i = 0; i < t; i++)
    {
        if (ans[i])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    system("pause");
}