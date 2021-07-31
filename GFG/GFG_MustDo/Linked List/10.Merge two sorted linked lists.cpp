/* Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
1 <= Node's data <= 105 */

Node *sortedMerge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *head = a;
    if (a->data > b->data)
    {
        head = b;
        b = b->next;
    }
    else
    {
        a = a->next;
    }

    Node *cur = head;
    while (a && b)
    {
        if (a->data < b->data)
        {
            cur->next = a;
            a = a->next;
        }
        else
        {
            cur->next = b;
            b = b->next;
        }
        cur = cur->next;
    }

    if (!a)
        cur->next = b;
    else
        cur->next = a;
    return head;
}