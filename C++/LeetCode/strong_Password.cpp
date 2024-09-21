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
    string str1;
    string str2;
    string sum;

    cin >> str1 >> str2;

    string &max = str1.length() > str2.length() ? str1 : str2;
    string &min = (max == str1) ? str2 : str1;

    for (int i = 0; i < min.length() * 2; i++)
    {
        if (i % 2)
        {
            sum += (str2[i / 2]);
        }
        else
            sum += (str1[i / 2]);
    }

    sum += (max.substr(min.length(), max.length() - min.length()));
    cout << sum;
}