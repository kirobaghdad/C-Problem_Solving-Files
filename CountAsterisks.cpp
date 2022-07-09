#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int count = 0;
    string str;
    cin >> str;
    stack<char> aster;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '*')
        {
            if (aster.size() == 0)
                count++;
        }
        else if (str[i] == '|')
        {
            if (aster.size() == 0)
                aster.push(str[i]);
            else
                aster.pop();
        }
    }
    cout << count;
}