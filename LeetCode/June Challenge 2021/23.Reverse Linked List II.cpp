// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *curr = head; // for iterating in the list
        ListNode *prev = NULL; // tracking previous node in the list
        int cnt = 0;           // helps to find left and right position in the list
        while (curr != NULL)
        {
            cnt++;
            if (cnt == left)
            {
                // reversal of [left,right] starts
                ListNode *inner_curr = curr;
                ListNode *inner_prev = NULL;
                while (cnt <= right)
                {
                    ListNode *forward = inner_curr->next;
                    inner_curr->next = inner_prev;
                    inner_prev = inner_curr;
                    inner_curr = forward;
                    cnt++;
                }
                // reversal ends here
                // now, we have to adjust the original list
                if (prev != NULL) // check left must not be start of the list
                    prev->next = inner_prev;
                else
                    head = inner_prev; // if left is the start of the list, we have new head
                curr->next = inner_curr;
                curr = inner_curr;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};