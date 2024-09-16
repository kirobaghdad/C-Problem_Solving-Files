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
    ListNode *deleteMiddle(ListNode *head)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int c = 0;

        ListNode *temp = head;
        ListNode *temp1 = head;

        while (temp)
        {
            c++;
            temp = temp->next;
        }

        if (c == 1)
            return nullptr;

        temp = nullptr;
        temp1 = head;

        for (int i = 0; i < c / 2; i++)
        {

            if (i == 0)
                temp = head;
            else
                temp = temp->next;

            temp1 = temp1->next;
        }

        temp->next = temp1->next;
        temp1->next = nullptr;

        delete temp1;

        return head;
    }
};

int main()
{
    Solution s;

    // ListNode *temp = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(7, new ListNode(1, new ListNode(2, new ListNode(6)))))));

    s.deleteMiddle(new ListNode(1));

    return 0;
}