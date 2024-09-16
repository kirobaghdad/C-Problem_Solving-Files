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
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int num;
    int min;
    for (int i = 0; i < n; i++)
    {
        min = INT_MAX;
        num = 1;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                num = 1;
            }
            else if (arr[j] == min)
            {
                num++;
            }
        }
        cout << num << " ";
    }
}