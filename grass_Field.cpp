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
    int t = 0;
    cin >> t;
    int arr[4];
    int sum = 0;
    int *ans = new int[t];

    for (int i = 0; i < t; i++)
    {
        sum = 0;
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        sum = arr[0] + arr[1] + arr[2] + arr[3];
        if (sum == 0)
            ans[i] = 0;
        else if (sum == 4)
            ans[i] = 2;
        else
            ans[i] = 1;
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
}