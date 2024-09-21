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
    void solve(ListNode *node, int &rem)
    {
        if (node->next)
            solve(node->next, rem);

        int temp = node->val * 2 + rem;

        node->val = temp % 10;

        rem = temp / 10;
    }

    ListNode *doubleIt(ListNode *head)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int rem = 0;
        solve(head, rem);

        if (rem)
        {
            ListNode *newNode = new ListNode(rem);
            ListNode *temp = head;
            head = newNode;
            head->next = temp;
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode *ans = s.doubleIt(new ListNode(9, new ListNode(9, new ListNode(9))));

    while (ans)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}