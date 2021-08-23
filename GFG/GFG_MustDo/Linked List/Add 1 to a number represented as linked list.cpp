/* A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000 */

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *cur = head;
        Node *next = NULL;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    Node *addOne(Node *head)
    {
        Node *rev = reverse(head);
        Node *cur = rev;
        while (cur)
        {
            if (cur->data == 9)
            {
                cur->data = 0;
            }
            else
            {
                cur->data++;
                Node *act = reverse(rev);
                return act;
            }
            cur = cur->next;
        }
        Node *act = reverse(rev);

        Node *node = new Node(1);
        node->next = act;
        act = node;
        return act;
    }
};