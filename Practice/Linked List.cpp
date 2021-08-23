#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x;
    Node *next;
    Node(int i)
    {
        x = i;
        next = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void insert(int i)
{
    Node *node = new Node(i);
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }
}
void print(Node *head)
{
    Node *cur = head;
    if (!head)
    {
        cout << "NULL";
    }
    while (cur)
    {
        cout << cur->x << " -> ";
        cur = cur->next;
    }
    cout << "NULL";
}
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

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next and fast->next->next)
    {
        if (fast->next == NULL)
        {
            slow = slow->next;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    //   cout<<"\nMid Value: "<<slow->next->x;
    return slow->next;
}

bool palind(Node *head)
{
    Node *mid = findMid(head);
    Node *p2 = reverse(mid);
    Node *p1 = head;
    while (p2)
    {
        if (p1->x != p2->x)
        {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
void deletelast(Node **head, int val)
{
    Node **occur = NULL;
    while ((*head))
    {
        if ((*head)->x == val)
        {
            occur = head;
        }
        head = &(*head)->next;
    }
    if (occur)
    {
        Node *tmp = *occur;
        *occur = tmp->next;
        free(tmp);
    }
}

int main()
{
    insert(1);
    insert(4);
    insert(3);
    insert(4);
    insert(4);
    //   insert(1);

    cout << "Original Lineked list: ";
    print(head);
    cout << "\nChaged Lineked list: ";
    deletelast(&head, 4);
    print(head);
    //   Node *mid=findMid(head);
    //   Node *rev=reverse(mid);
    //   cout<<"\nAfter reverse 1st half part: ";
    //   print(head);

    //   cout<<"\nAfter reverse 2nd half part: ";
    //   print(rev);
    //   cout<<"\nreverse Lineked list: ";
    //   print(rev);
    //   if(palind(head))
    //   { cout<<"\nLL is palindrome";  }
    //   else
    //   { cout<<"\nLL is not palindrome";  }
    return 0;
}