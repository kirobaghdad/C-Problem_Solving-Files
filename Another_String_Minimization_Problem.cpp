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
    int n, m;
    vector<int> nums;
    int in;
    vector<string> arr;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        string str(m, 'B');

        for (int j = 0; j < n; j++)
        {
            cin >> in;
            if (str[m - in] == str[in - 1])
            {
                if (in > m + 1 - in)
                {
                    str[m - in] = 'A';
                }
                else
                {
                    str[in - 1] = 'A';
                }
            }
            else if (str[m - in] == 'B')
            {
                str[m - in] = 'A';
            }
            else
            {
                str[in - 1] = 'A';
            }

            nums.push_back(in);
        }
        nums.clear();
        arr.push_back(str);
    }

    for (int i = 0; i < t; i++)
        cout << arr[i] << endl;

    return 0;
}
