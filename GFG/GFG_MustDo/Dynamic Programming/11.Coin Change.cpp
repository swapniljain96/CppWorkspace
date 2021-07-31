/* Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.


Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n).


Constraints:
1 <= n,m <= 103 */

class Solution
{
public:
    long long int count(int a[], int n, int w)
    {
        long long int t[n + 1][w + 1];
        memset(t, 0, sizeof(t));
        for (int i = 0; i < n + 1; i++)
        {
            t[i][0] = 1;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (a[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j] + t[i][j - a[i - 1]];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][w];
    }
};
