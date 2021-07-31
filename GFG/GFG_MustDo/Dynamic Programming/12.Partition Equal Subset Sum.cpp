/* Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000 */

class Solution
{
public:
    bool subset(int n, int a[], int x)
    {
        bool t[n + 1][x + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < x + 1; j++)
            {
                if (i == 0)
                {
                    t[i][j] = false;
                }
                else if (j == 0)
                {
                    t[i][j] = true;
                }
                else if (a[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][x];
    }
    int equalPartition(int n, int a[])
    {
        int sum;
        bool flag;
        sum = accumulate(a, a + n, 0);
        if (sum % 2 != 0)
            return false;
        else
        {
            flag = subset(n, a, sum / 2);
        }
        return flag;
    }
};