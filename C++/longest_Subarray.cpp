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

    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int num = 0;
    int sum = 0;
    i = 0;
    int j = 0;
    while (i < n)
    {
        sum = 0;
        num = 0;
        while (j < n)
        {
            sum += arr[j];
            if ((sum) % k == 0 || sum < k)
            {
                num++;
            }
            else
            {
                i = j;
                break;
            }
            j++;
        }
        i++;
    }
}