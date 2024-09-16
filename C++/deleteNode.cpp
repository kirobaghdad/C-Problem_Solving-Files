#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        ListNode *temp0 = node;
        ListNode *temp1 = node->next;

        while (temp1->val != node->val)
        {
            temp0 = temp0->next;
            temp1 = temp1->next;
        }

        temp0->next = temp1->next;

        temp1->next = nullptr;
        delete temp1;
        temp1 = nullptr;
    }
};

int main()
{
    Solution s;

    // ListNode* ln = new ListNode(4 ,new ListNode(1 ,new ListNode(2 ,new ListNode(9)));
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    ListNode *l1 = new ListNode(1);
    ListNode *l9 = new ListNode(9);

    l4->next = l5;
    l5->next = l1;
    l9->next = l9;

    s.deleteNode(new ListNode(1));

    return 0;
}