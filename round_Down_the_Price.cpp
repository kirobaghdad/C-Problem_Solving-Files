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
    int n;
    int *ans = new int[t];

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ans[i] = n - pow(10, floor(log10(n)));
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
    ;

    system("pause");
}