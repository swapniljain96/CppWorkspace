/* Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 5
value[] = {2, 4, 7, 8, 9}
k = 3
Output: 8 9 2 4 7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7
Example 2:

Input:
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function rotate() which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
1 <= k <= N */

// Method 1:
class Solution
{
public:
    //Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        Node *newStart = NULL;
        Node *pos = head;
        Node *end = head;
        int cnt = 1; //bcoz we ae counting 1st head node also
        while (end->next != NULL)
        {
            end = end->next;
            cnt++;
        }
        if (cnt == k)
        {
            return head;
        }

        k--;
        while (k--)
        {
            pos = pos->next;
        }

        newStart = pos->next;
        pos->next = NULL;
        end->next = head;

        return newStart;
    }
};

// Method 2:

class Solution
{
public:
    //Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        Node *rotate = head;
        Node *end = head;
        while (end->next)
        {
            end = end->next;
        }
        k--;
        while (k--)
        {
            rotate = rotate->next;
        }
        end->next = head;
        head = rotate->next;
        rotate->next = NULL;
        return head;
    }
};