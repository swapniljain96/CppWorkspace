/* Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= N <= 105 */

// Steps: 1.find the middle node of the linked list according to even and odd.
//        2.Reverse the LL after the middle node.
//        3.Compare start node of LL to the start of reverse LL.

class Solution
{
public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        int len = 0;
        int odd = 0;
        Node *l = head;
        while (l)
        {
            len++;
            l = l->next;
        }
        if (len % 2 == 1)
        {
            odd = 1;
        }
        int finlen = (len / 2) + odd;

        Node *cur = head;
        while (finlen--)
        {
            cur = cur->next;
        }

        Node *prev = NULL;
        Node *curr = cur;
        Node *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        Node *start = head;
        while (prev != NULL)
        {
            if (start->data != prev->data)
            {
                return false;
            }
            start = start->next;
            prev = prev->next;
        }
        return true;
    }
};