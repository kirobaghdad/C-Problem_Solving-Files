#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        vector<ListNode *> l;

        while (head)
        {
            if (find(l.begin(), l.end(), head->next) != l.end())
            {
                return true;
            }

            l.push_back(head);
            head = head->next;
        }

        return false;
    }
};

int main()
{
    ListNode *l = new ListNode(3, new ListNode(2, new ListNode(0, new ListNode(-4))));
    Solution s;

    cout << s.hasCycle(l) << endl;

    return 0;
}