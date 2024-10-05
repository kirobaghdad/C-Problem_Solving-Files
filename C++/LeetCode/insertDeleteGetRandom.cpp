#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
public:
    unordered_set<int> s;

    RandomizedSet()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool insert(int val)
    {
        if (s.count(val))
            return false;

        s.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (!s.count(val))
            return false;

        s.erase(s.find(val));

        return true;
    }

    int getRandom()
    {
        auto it = s.begin();
        advance(it, rand() % s.size());
        return *(it);
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{

    return 0;
}