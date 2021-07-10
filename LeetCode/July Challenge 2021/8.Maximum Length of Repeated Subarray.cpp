/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
Example 1:
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100 */

class Solution
{
public:
    int findLength(vector<int> &a, vector<int> &b)
    {
        int x = a.size(), y = b.size();
        int t[x + 1][y + 1];
        memset(t, 0, sizeof(t));
        int ans = 0;
        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                if (a[i - 1] == b[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    ans = max(ans, t[i][j]);
                }
                else
                {
                    t[i][j] = 0;
                }
            }
        }
        return ans;
    }
};