#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
    set<int> added;
    int start;

public:
    SmallestInfiniteSet()
    {
        start = 1;
    }

    int popSmallest()
    {
        if (!added.size() || start < *added.begin())
        {
            start++;
            return start - 1;
        }
        else
        {
            int temp = *added.begin();
            added.erase(temp);
            return temp;
        }
    }

    void addBack(int num)
    {
        if (num < start)
        {
            added.insert(num);
        }
    }
};

int main()
{
    SmallestInfiniteSet s;

    return 0;
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */