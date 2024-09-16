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
    int num;
    int n;
    vector<int> ans;
    int sum;
    int zeros;
    bool firstNonZero;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        sum = 0;
        zeros = 0;
        firstNonZero = 0;

        for (int j = 0; j < n - 1; j++)
        {
            cin >> num;
            if (num == 0)
            {
                if (firstNonZero)
                {
                    zeros++;
                }
            }
            else
            {
                if (!firstNonZero)
                    firstNonZero = 1;
            }
            sum += num;
        }
        cin >> num;
        ans.push_back(zeros + sum);
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
}