#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    queue<int> requests;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        requests.push(t);

        queue<int> temp;

        int st;
        int count = 0;

        do
        {
            st = requests.front();
            requests.pop();

            temp.push(st);

            if (st <= t && st >= t - 3000)
                count++;
            else
                break;

        } while (requests.size() > 0);

        requests = temp;

        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
    RecentCounter *solution = new RecentCounter();

    cout << solution->ping(1) << endl;
    cout << solution->ping(100) << endl;
    cout << solution->ping(3001) << endl;
    cout << solution->ping(3002) << endl;

    return 0;
}