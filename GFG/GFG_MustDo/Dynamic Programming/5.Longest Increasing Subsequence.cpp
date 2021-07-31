/* Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.

Example 1:

Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6
Example 2:

Input:
N = 6
A[] = {5,8,3,7,9,1}
Output: 3
Explanation:Longest increasing subsequence
5 7 9, with length 3
Your Task:
Complete the function longestSubsequence() which takes the input array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( N*log(N) )
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
0 ≤ A[i] ≤ 106 */

class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int ans = 0;
        int t[n + 1];
        for (int i = 0; i <= n; i++)
            t[i] = INT_MAX;
        t[0] = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(t, t + n + 1, a[i]) - t;
            if (a[i] > t[index - 1] and a[i] < t[index])
            {
                t[index] = a[i];
            }
        }

        for (int i = n; i >= 0; i--)
        {
            if (t[i] != INT_MAX)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};