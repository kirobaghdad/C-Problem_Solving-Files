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
    stack<int> nums;

    bool solve(ListNode *head, int len, int i = 0)
    {
        if (head)

        {
            if (i < len / 2)
            {
                nums.push(head->val);
                return solve(head->next, len, i + 1);
            }
            if (len % 2 == 1)
            {
                if (i > len / 2)
                {
                    if (nums.top() != head->val)
                        return false;

                    nums.pop();
                    return solve(head->next, len, i + 1);
                }
                else
                {
                    return solve(head->next, len, i + 1);
                }
            }

            if (len % 2 == 0 && i >= len / 2)
            {
                if (nums.top() != head->val)
                    return false;

                nums.pop();
                return solve(head->next, len, i + 1);
            }
        }

        return true;
    }

    bool isPalindrome(ListNode *head)
    {

        ListNode *p2 = head;
        int len = 0;

        while (p2)
        {
            p2 = p2->next;
            len++;
        }

        return solve(head, len);
    }
};

int main()
{
    Solution s;

    ListNode *l = new ListNode(1, new ListNode(0, new ListNode(0)));

    cout << s.isPalindrome(l);

    return 0;
}