
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

void solve(Node *root, vector<int> &v)
{
    if (!root)
        return;
    v.push_back(root->data);
    solve(root->left, v);
    solve(root->right, v);
}
vector<int> preorder(Node *root)
{
    vector<int> v;
    solve(root, v);
    return v;
}

// Method 2 (a): Iterative

vector<int> preorder(Node *root)
{
    vector<int> v;
    stack<Node *> s;
    Node *p = root;
    while (1)
    {
        while (p)
        {
            v.push_back(p->data);
            s.push(p);
            p = p->left;
        }

        if (s.empty())
            break;
        p = s.top();
        s.pop();
        p = p->right;
    }
    return v;
}

// Method 2 (b): Iterative

vector<int> preorder(Node *root)
{
    vector<int> v;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *tmp = s.top();
        s.pop();
        v.push_back(tmp->data);
        if (tmp->right)
            s.push(tmp->right);
        if (tmp->left)
            s.push(tmp->left);
    }

    return v;
}