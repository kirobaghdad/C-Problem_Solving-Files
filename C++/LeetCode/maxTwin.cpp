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
    int pairSum(ListNode *head)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        stack<int> nums;

        ListNode *temp = head;

        while (temp)
        {
            nums.push(temp->val);
            temp = temp->next;
        }

        int ans = -1;
        int n = nums.size();

        for (int i = 0; i < n / 2; i++)
        {
            if (head->val + nums.top() > ans)
                ans = head->val + nums.top();

            nums.pop();
            head = head->next;
        }

        return ans;
    }
};
int main()
{
    Solution s;

    cout << s.pairSum(new ListNode(5, new ListNode(4, new ListNode(3, new ListNode(1)))));

    return 0;
}