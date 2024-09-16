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

int main()
{
    int t;
    cin >> t;
    string str;
    int *ans = new int[t];
    int n = 0;
    string diff;

    for (int i = 0; i < t; i++)
    {
        n = 0;
        diff = "";
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {

            if (diff.length() == 3)
            {
                while (j < str.length() && (diff.find(str[j]) != string::npos))
                {
                    j++;
                }
                n++;
                diff = "";
            }

            if (j < str.length() && diff.find(str[j]) == string::npos)
            {
                diff.push_back(str[j]);
            }
        }
        if (diff.length() != 0)
            n++;
        ans[i] = n;
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    system("pause");
    delete[] ans;
    return 0;
}