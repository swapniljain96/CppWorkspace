/* Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.

It is guaranteed that there will be a rectangle with a sum no larger than k.
Example 1:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
Example 2:

Input: matrix = [[2,2,-1]], k = 3
Output: 3

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-105 <= k <= 105 */

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        // prefix sum of every row
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < m; j++)
                matrix[i][j] += matrix[i][j - 1];
        }
        // try every possible width of subarray
        for (int start = 0; start < m; start++)
        {
            for (int end = start; end < m; end++)
            {
                set<int> s = {0};
                int pref_sum = 0;
                // for current width of rectangle
                for (int i = 0; i < n; i++)
                {
                    int sum = matrix[i][end];
                    if (start > 0)
                        sum -= matrix[i][start - 1];
                    pref_sum += sum;
                    auto itr = s.lower_bound(pref_sum - k);
                    if (itr != s.end())
                        ans = max(ans, pref_sum - (*itr));
                    s.insert(pref_sum);
                }
            }
        }
        return ans;
    }
};