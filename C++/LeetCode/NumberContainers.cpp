#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
    unordered_map<int, int> m1;
    unordered_map<int, set<int>> m2;

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        m2[m1[index]].erase(index);
        if (m2[m1[index]].size() == 0)
            m2.erase(m1[index]);

        m2[number].insert(index);

        m1[index] = number;
    }

    int find(int number)
    {
        if (m2.find(number) != m2.end())
            return *(m2[number].begin());
        else
            return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}