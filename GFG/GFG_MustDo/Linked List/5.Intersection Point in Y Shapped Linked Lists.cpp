/* Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:

Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ N + M ≤ 2*105
-1000 ≤ value ≤ 1000*/

int intersectPoint(Node *head1, Node *head2)
{
    int c1 = 0, c2 = 0;
    Node *l1 = head1;
    Node *l2 = head2;
    while (l1)
    {
        c1++;
        l1 = l1->next;
    }
    while (l2)
    {
        c2++;
        l2 = l2->next;
    }
    int diff = abs(c1 - c2);
    Node *p1 = head1;
    Node *p2 = head2;
    if (c1 > c2)
    {
        while (diff--)
        {
            p1 = p1->next;
        }
    }
    else
    {
        while (diff--)
        {
            p2 = p2->next;
        }
    }

    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1->data;
}