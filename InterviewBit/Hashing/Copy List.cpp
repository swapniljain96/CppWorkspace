/* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, 
but a copy of them. The pointers in the returned list should not link to any node in the original input list. */

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

// Method 1: TC=O(n) SC=O(n)
RandomListNode *Solution::copyRandomList(RandomListNode *head)
{
    unordered_map<RandomListNode *, RandomListNode *> m;
    RandomListNode *copyhead = new RandomListNode(head->label);
    RandomListNode *original = head;
    RandomListNode *copy = copyhead;
    m[original] = copy;
    while (original)
    {
        if (original->next)
        {
            RandomListNode *node = new RandomListNode(original->next->label);
            copy->next = node;
            copy = copy->next;
        }
        original = original->next;
        m[original] = copy;
    }

    RandomListNode *op = head;
    RandomListNode *cp = copyhead;
    while (op)
    {
        cp->random = op->random != NULL ? m[op->random] : NULL;
        op = op->next;
        cp = cp->next;
    }

    return copyhead;
}

// Method 2: TC=O(n) SC=O(1)

RandomListNode *Solution::copyRandomList(RandomListNode *A)
{
    //step 1
    RandomListNode *copy = NULL, *curr = A, *nex = NULL;
    while (curr)
    {
        copy = new RandomListNode(curr->label); //1 copy
        nex = curr->next;                       //2
        curr->next = copy;
        copy->next = nex;
        curr = nex;
    }

    //step 2
    curr = A;
    while (curr)
    {

        curr->next->random = (curr->random) ? curr->random->next : NULL;
        nex = curr->next->next;
        curr->next->next = (curr->next->next == NULL) ? NULL : curr->next->next->next;
        curr = nex;
    }

    return A->next;
}
