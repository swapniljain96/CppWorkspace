/* Given a string S, implement Huffman Encoding and Decoding.

Example 1:

Input : abc
Output : abc
Example 2: 

Input : geeksforgeeks
Output : geeksforgeeks
 

Your task: 
You don't need to read input or print anything. Your task is to complete the function decode_file(), which takes root of the tree formed while encoding and the encoded string as the input parameters and returns the decoded string.

 

Constraints:
2<=S<=1000 */

string decode_file(struct MinHeapNode *root, string s)
{
    string ans = "";
    struct MinHeapNode *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
        if (!curr->left and !curr->right)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans + '\0';
}