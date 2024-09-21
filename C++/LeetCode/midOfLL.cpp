#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (!head)
            return nullptr;

        int i = 0;
        ListNode *temp = head;

        while (temp)
        {
            temp = temp->next;
            i++;
        }

        temp = head;

        for (int k = 0; k < i / 2; k++)
            temp = temp->next;

        return temp;
    }
};

int main()
{
    ListNode *l = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6))))));
    Solution s;

    cout << s.middleNode(l)->val;

    return 0;
}