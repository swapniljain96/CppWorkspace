/* Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000 */

class Solution
{
public:
    Node *reverse(Node *root)
    {
        Node *prev = NULL;
        Node *cur = root;
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
    struct Node *addTwoLists(struct Node *na, struct Node *nb)
    {
        Node *a = reverse(na);
        Node *b = reverse(nb);
        Node *dummy = new Node(0);
        Node *cur = dummy;
        int carry = 0;
        while (a || b || carry)
        {
            int sum = 0;
            if (a)
            {
                sum += a->data;
                a = a->next;
            }
            if (b)
            {
                sum += b->data;
                b = b->next;
            }
            sum += carry;
            carry = sum / 10;
            Node *node = new Node(sum % 10);
            cur->next = node;
            cur = cur->next;
        }
        Node *head = reverse(dummy->next);
        return head;
    }
};