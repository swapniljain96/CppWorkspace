/* A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1 */

// Method 1: using 2 pointers technique
// TC=O(n) SC=O(1)
class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &a, int n)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (a[i][j])    // i knows j, means i cannot be a celebrity bcoz celebrity doesn't know anyone
                i++;
            else            // j knows i,(same)
                j--;
        }
        int x = i;          //now x is our potential candidate,now we check in its row and column  
        //  Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one
        for (int i = 0; i < n; i++) 
        {
            if (x != i && (a[i][x] == 0 || a[x][i] == 1))
                return -1;
        }
        return x;
    }
};

// Method 2: using stack technique
// TC=O(n) SC=O(n)
class Solution
{
public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &a, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
            s.push(i);
        while (s.size() > 1)
        {
            int i = s.top();
            s.pop();
            int j = s.top();
            s.pop();
            if (a[i][j])     // i knows j, means i cannot be a celebrity bcoz celebrity doesn't know anyone
                s.push(j);
            else
                s.push(i);   // j knows i,(same)
        }
        if (s.empty())
            return -1;
        int x = s.top();    //now x is our potential candidate,now we check in its row and column
        for (int i = 0; i < n; i++)
        {
            if (x != i && (a[i][x] == 0 || a[x][i] == 1))
                return -1;
        }
        return x;
    }
};