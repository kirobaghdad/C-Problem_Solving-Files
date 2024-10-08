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

ListNode *reverseList(ListNode *head)
{
    ListNode *pre = NULL;
    ListNode *temp = head;
    ListNode *temp1 = head;

    while (temp)
    {
        temp1 = temp->next;
        temp->next = pre;
        pre = temp;
        temp = temp1;
    }

    return pre;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    ListNode *ans = reverseList(head);

    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}