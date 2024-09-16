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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;

        if (!head->next)
            return head;

        ListNode *temp = head;
        ListNode *temp1;

        ListNode *prev = nullptr;

        ListNode *ans = temp->next;

        while (temp)
        {
            temp1 = temp->next;

            if (!temp1)
                break;

            temp->next = temp1->next;
            temp1->next = temp;

            if (prev != nullptr)
                prev->next = temp1;

            prev = temp;

            temp = temp->next;
        }

        return ans;
    }
};

int main()
{
    Solution s;

    ListNode *l = new ListNode(1, new ListNode(2, new ListNode(3)));

    s.swapPairs(l);

    return 0;
}