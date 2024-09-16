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
    int n, x;
    vector<int> people;
    int num;
    bool *ans = new bool[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n >> x;
        ans[i] = 1;
        for (int j = 0; j < 2 * n; j++)
        {
            cin >> num;
            people.push_back(num);
        }
        sort(people.begin(), people.end());

        for (int j = 0; j < n; j++)
        {
            if ((people[j + n] - people[j]) < x)
            {
                ans[i] = 0;
                break;
            }
        }
        people.clear();
    }

    for (int i = 0; i < t; i++)
        ans[i] ? cout << "YES" << endl : cout << "NO" << endl;
    delete[] ans;
}