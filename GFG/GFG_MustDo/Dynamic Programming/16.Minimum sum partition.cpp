/* Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value


Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)


Constraints:
1 ≤ N*|sum of array elements| ≤ 106 */

class Solution
{

public:
    int minDifference(int a[], int n)
    {
        int sum = accumulate(a, a + n, 0);
        bool t[n + 1][sum + 1];
        memset(t, false, sizeof(t));
        for (int i = 0; i < n + 1; i++)
        {
            t[i][0] = true;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (a[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < sum / 2 + 1; j++)
        {
            if (t[n][j] == true)
            {
                ans = min(ans, sum - (2 * j));
            }
        }
        return ans;
    }
};