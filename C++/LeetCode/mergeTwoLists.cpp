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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;

        ListNode *ans = nullptr;
        ListNode *p = nullptr;

        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                if (ans == nullptr)
                {
                    ans = list2;
                    list2 = list2->next;
                    ans->next = nullptr;
                }
                else
                {
                    p = ans;

                    while (p->next)
                        p = p->next;

                    p->next = list2;

                    list2 = list2->next;
                    p = p->next;
                    p->next = nullptr;
                }
            }
            else
            {
                if (ans == nullptr)
                {
                    ans = list1;
                    list1 = list1->next;
                    ans->next = nullptr;
                }
                else
                {
                    p = ans;

                    while (p->next)
                        p = p->next;

                    p->next = list1;

                    list1 = list1->next;
                    p = p->next;
                    p->next = nullptr;
                }
            }
        }

        if (list1)
        {
            p = ans;

            while (p->next)
                p = p->next;

            p->next = list1;
        }
        else if (list2)
        {
            p = ans;

            while (p->next)
                p = p->next;

            p->next = list2;
        }

        return ans;
    }
};

int main()
{
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(1);

    Solution s;

    s.mergeTwoLists(p1, p2);

    return 0;
}