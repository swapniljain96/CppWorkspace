/* Given the head of a singly linked list, return true if it is a palindrome.

Example 1:

Input: head = [1,2,2,1]
Output: true
Example 2:

Input: head = [1,2]
Output: false

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9

Follow up: Could you do it in O(n) time and O(1) space? */
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
    ListNode *rev(ListNode *root)
    {
        ListNode *prev = NULL, *cur = root, *next = NULL;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        int n = 0;
        ListNode *cur = head;
        while (cur)
        {
            n++;
            cur = cur->next;
        }
        cout << "n: " << n;
        cur = head;
        if (n % 2 == 0)
        {
            n = n / 2;
        }
        else
        {
            n = n / 2 + 1;
        }
        while (n--)
        {
            cur = cur->next;
        }
        ListNode *revp = rev(cur);
        cur = head;
        while (revp)
        {
            if (cur->val != revp->val)
            {
                return false;
            }
            cur = cur->next;
            revp = revp->next;
        }
        return true;
    }
};