/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz */

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int n = 0;
        ListNode *curr = head, *prev, *next_node, *start_prev, *start_curr;
        while (curr != NULL)
            n++, curr = curr->next;
        n = n / k;
        curr = head;
        for (int i = 0; i < n; i++)
        {
            prev = NULL;       // for every segment, prev = NULL
            start_curr = curr; // track the starting node of every segment
            for (int j = 0; j < k; j++)
            { // reverse arrows for a particular segment
                next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }
            if (i == 0) // our head node changes here
                head = prev;
            if (i > 0) // connect two consecutive segments
                start_prev->next = prev;
            start_prev = start_curr; // change start_prev
        }
        if (start_curr) // last segment start node must have next node
            start_curr->next = curr;
        return head;
    }
};