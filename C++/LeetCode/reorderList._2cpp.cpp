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
    void reorderList(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *cur2 = reverse(slow->next);
        slow->next = NULL;
        fast = head;
        ListNode *temp = head;
        while (cur2)
        {
            temp = fast->next;
            fast->next = cur2;
            fast = temp;
            temp = cur2->next;
            cur2->next = fast;
            cur2 = temp;
        }
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = NULL;
        ListNode *temp = head;
        while (cur)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    s.reorderList(head);

    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}