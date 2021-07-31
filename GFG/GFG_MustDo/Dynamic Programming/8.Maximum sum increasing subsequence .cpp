/* Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 

Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
Example 2:

Input: N = 3, arr[] = {1, 2, 3}
Output: 6
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3}

Your Task:  
You don't need to read input or print anything. Complete the function maxSumIS() which takes N and array arr as input parameters and returns the maximum value.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105 */

class Solution
{

public:
    int maxSumIS(int a[], int n)
    {
        vector<int> t(n);
        for (int j = 0; j < n; j++)
        {
            t[j] = a[j];
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (a[i] < a[j])
                {
                    t[j] = max(t[j], t[i] + a[j]);
                }
            }
        }
        return *max_element(t.begin(), t.end());
    }
};