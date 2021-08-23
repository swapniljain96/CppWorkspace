#include <bits/stdc++.h>
using namespace std;

struct tnode
{
    int data;
    tnode *left;
    tnode *right;
    tnode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void preorder(tnode *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(tnode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(tnode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

tnode *insert(tnode *root, int val)
{
    if (!root)
        return new tnode(val);
    if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
}

void search(tnode *root, int ele)
{
    if (!root)
    {
        cout << ele << " not found ;)";
        return;
    }

    if (root->data == ele)
    {
        cout << ele << " found !!!!!";
        return;
    }
    else if (root->data > ele)
    {
        search(root->left, ele);
    }
    else
    {
        search(root->right, ele);
    }
}
struct tnode *minValueNode(struct tnode *node)
{
    struct tnode *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

//Function to delete a node from BST.
tnode *deleteNode(tnode *root, int key)
{ // base case
    if (root == NULL)
        return root;
    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // node has no child
        if (root->left == NULL and root->right == NULL)
            return NULL;

        // node with only one child or no child
        else if (root->left == NULL)
        {
            struct tnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct tnode *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct tnode *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

tnode *root = NULL;
int main()
{
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 45);
    insert(root, 79);
    insert(root, 36);
    insert(root, 78);
    insert(root, 89);
    insert(root, 12);
    insert(root, 43);
    insert(root, 53);
    //   root->left=new tnode(5);
    //   root->right=new tnode(17);
    //   root->left->left=new tnode(2);
    //   root->left->right=new tnode(8);
    //   root->right->left=new tnode(16);
    //   root->right->right=new tnode(18);
    //   root->left->left->left=new tnode(1);
    //   root->left->left->right=new tnode(4);
    //   root->left->right->left=new tnode(7);
    search(root, 100);

    cout << "\nPreorder:";
    preorder(root);
    cout << "\nInorder:";
    inorder(root);
    cout << "\nPostorder:";
    postorder(root);
    return 0;
}