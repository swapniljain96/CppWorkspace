
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// Method 1: Recursive

class Solution
{
public:
    void helper(Node *root, vector<int> &v)
    {
        if (!root)
            return;
        helper(root->left, v);
        v.push_back(root->data);
        helper(root->right, v);
    }
    vector<int> inOrder(Node *root)
    {
        vector<int> v;
        helper(root, v);
        return v;
    }
};

// Method 2: Iterative

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        vector<int> v;
        stack<Node *> s;
        Node *p = root;
        while (1)
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }

            if (s.empty())
                break;

            p = s.top();
            s.pop();
            v.push_back(p->data);
            p = p->right;
        }
        return v;
    }
};