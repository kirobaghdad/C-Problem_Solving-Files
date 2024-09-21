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
    int **arr = new int *[t];
    int b;
    char in;
    int *nS = new int[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        nS[i] = n;
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

        for (int j = 0; j < n; j++)
        {
            cin >> b;
            for (int k = 0; k < b; k++)
            {
                cin >> in;

                if (in == 'D')
                    arr[i][j] = (arr[i][j] + 1) % 10;
                else
                {
                    if (arr[i][j])
                        arr[i][j] = (arr[i][j] - 1);
                    else
                        arr[i][j] = 9;
                }
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < nS[i]; j++)
            cout << arr[i][j] << " ";
        delete[] arr[i];
        cout << endl;
    }

    delete[] nS;
}