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

// class Solution
// {
// public:
//     void reorderList(ListNode *head)
//     {
//         if (head == NULL || head->next == NULL || head->next->next == NULL)
//             return;

//         ListNode *slow = head;
//         ListNode *fast = head;

//         stack<int> st;

//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode *temp = slow->next;
//         while (temp != NULL)
//         {
//             st.push(temp->val);
//             temp = temp->next;
//         }

//         slow->next = NULL;

//         temp = head;

//         while (!st.empty())
//         {
//             ListNode *nxt = temp->next;
//             temp->next = new ListNode(st.top());
//             st.pop();
//             temp->next->next = nxt;
//             temp = nxt;
//         }
//     }
// };

class Solution
{

public:
    void reorderList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *temp1;

        int count = 0;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        stack<ListNode *> s;
        temp = head;

        for (int i = 0; i < ceil((count + 0.0) / (2.0)) - 1; i++)
        {
            temp = temp->next;
        }

        temp1 = temp->next;
        temp->next = nullptr;
        temp = temp1;
        temp1 = head;

        while (temp)
        {
            s.push(temp);
            temp = temp->next;
        }

        // ListNode *prev = nullptr;

        while (temp1)
        {
            temp = temp1->next;

            if (s.size())
            {
                temp1->next = s.top();
                s.pop();

                temp1->next->next = temp;

                // if (prev)
                //     prev->next = temp1;

                // prev = s.top();
            }
            else
            {
                if (temp1->next)
                    temp1->next->next = temp;
            }

            temp1 = temp;
        }
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    s.reorderList(head);

    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}