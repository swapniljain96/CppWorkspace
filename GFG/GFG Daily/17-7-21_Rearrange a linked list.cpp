/* Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.
Example 1:
Input:
LinkedList: 1->2->3->4
Output: 1 3 2 4 
Explanation: 
Odd elements are 1, 3 and even elements are 
2, 4. Hence, resultant linked list is 
1->3->2->4.
Example 2:
Input:
LinkedList: 1->2->3->4->5
Output: 1 3 5 2 4 
Explanation: 
Odd elements are 1, 3, 5 and even elements are
2, 4. Hence, resultant linked list is
â€‹1->3->5->2->4.
Your Task:
The task is to complete the function rearrangeEvenOdd() which rearranges the nodes in the linked list as required and doesn't return anything.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1 <= Size of the linked list <= 10000
1 <= values of linked list<= 1000 */

class Solution
{
public:
    void rearrangeEvenOdd(Node *head)
    {
        Node *odd = head;
        Node *even = head->next;
        Node *evenFirst = even;
        while (1)
        {
            if (!odd || !even || !(even->next))   // reach the end
            {
                odd->next = evenFirst;           // connect the odd and even list  bcoz both odd and even are traversed
                break;                          // so now odd ka next is equal to even the first which we already take as evenFirst
            }
            odd->next = even->next;
            odd = even->next;
            if (odd->next == NULL)
            {
                even->next = NULL;
                odd->next = evenFirst;
                break;
            }
            even->next = odd->next;
            even = odd->next;
        }
    }
};