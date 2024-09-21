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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int temp = 0;

        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        int len1 = 0;
        int len2 = 0;

        while (temp1)
        {
            len1++;
            temp1 = temp1->next;
        }

        while (temp2)
        {
            len2++;
            temp2 = temp2->next;
        }

        if (len1 >= len2)
        {
            temp1 = l1;
        }
        else
            temp1 = l2;

        if (len1 >= len2)
        {
            while (l1)
            {
                if (l2)
                {
                    if (l1->val + l2->val + temp > 9)
                    {
                        int t = ((l1->val + l2->val + temp) / 10);
                        l1->val = (l1->val + l2->val + temp) % 10;
                        temp = t;
                    }
                    else
                    {
                        l1->val = l1->val + l2->val + temp;
                        temp = 0;
                    }
                }
                else
                {
                    if (l1->val + temp > 9)
                    {
                        int t = ((l1->val + temp) / 10);
                        l1->val = (l1->val + temp) % 10;
                        temp = t;
                    }
                    else
                    {
                        l1->val = l1->val + temp;
                        temp = 0;
                    }
                }

                temp2 = l1;

                if (l2 != nullptr)
                    l2 = l2->next;

                l1 = l1->next;
            }

            if (temp != 0)
            {
                ListNode *newNode = new ListNode(temp);
                temp2->next = newNode;
            }
        }
        else
        {
            while (l2)
            {
                if (l1)
                {
                    if (l1->val + l2->val + temp > 9)
                    {
                        int t = (l1->val + l2->val + temp) / 10;
                        l2->val = (l1->val + l2->val + temp) % 10;
                        temp = t;
                    }
                    else
                    {
                        l2->val = l1->val + l2->val + temp;
                        temp = 0;
                    }
                }
                else
                {
                    if (l2->val + temp > 9)
                    {
                        int t = (l2->val + temp) / 10;
                        l2->val = (l2->val + temp) % 10;
                        temp = t;
                    }
                    else
                    {
                        l2->val = l2->val + temp;
                        temp = 0;
                    }
                }

                temp2 = l2;

                if (l1)
                    l1 = l1->next;

                l2 = l2->next;
            }

            if (temp != 0)
            {
                ListNode *newNode = new ListNode(temp);
                temp2->next = newNode;
            }
        }

        return temp1;
    }
};

int main()
{
    Solution s;

    // ListNode *root1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    // ListNode *root2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode *root1 = new ListNode(2, new ListNode(4, new ListNode(9)));
    ListNode *root2 = new ListNode(5, new ListNode(6, new ListNode(4, new ListNode(9))));

    ListNode *ans = s.addTwoNumbers(root1, root2);

    return 0;
}