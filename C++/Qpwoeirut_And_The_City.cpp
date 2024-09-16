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
    int n;
    vector<int> h;
    int num;
    vector<int> ans(t, 0);
    int temp;
    bool check;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        check = false;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            h.push_back(num);
        }

        if (n % 2 == 1)
        {
            for (int j = 1; j < n - 1; j = j + 2)
            {
                if (max(h[j - 1], h[j + 1]) >= h[j])
                    ans[i] += std::max(h[j - 1], h[j + 1]) - h[j] + 1;
            }
        }
        else
        {
            for (int j = 1; j < n - 1; j = j + 2)
            {
                if (max(h[j - 1], h[j + 1]) - h[j] < max(h[j], h[j + 2]) - h[j + 1] || check)
                {
                    if (max(h[j - 1], h[j + 1]) >= h[j])
                        ans[i] += max(h[j - 1], h[j + 1]) - h[j] + 1;
                }
                else
                {
                    if (max(h[j], h[j + 2]) >= h[j + 1])
                        ans[i] += max(h[j], h[j + 2]) - h[j + 1] + 1;
                    j++;
                    check = 1;
                }
            }
        }

        h.clear();
    }

    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << endl;
    }
}
