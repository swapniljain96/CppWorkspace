
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
    solve(root->left, v);
    solve(root->right, v);
    v.push_back(root->data);
}
vector<int> postOrder(Node *root)
{
    vector<int> v;
    solve(root, v);
    return v;
}

// Method 2: Iterative

vector<int> postOrder(Node *root)
{
    vector<int> v;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *p = s.top();
        s.pop();
        v.push_back(p->data);

        if (p->left)
            s.push(p->left);
        if (p->right)
            s.push(p->right);
    }
    reverse(begin(v), end(v));
    return v;
}