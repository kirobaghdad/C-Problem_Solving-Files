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
    int p;
    string *arr = new string[t];
    int price;

    for (int i = 0; i < t; i++)
    {
        cin >> str;
        price = 0;
        cin >> p;
        // vector<char> temp;

        for (int j = 0; j < str.length(); j++)
        {
            // temp.push_back(str[i]);
            price += str[j] - 'a' + 1;
        }

        while (price > p)
        {
            auto it = max_element(str.begin(), str.end());
            price = price - ((int)*it - 'a' + 1);
            str.erase(it);
        }

        arr[i] = str;
    }

    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << endl;
    }

    system("pause");
    delete[] arr;
    return 0;
}