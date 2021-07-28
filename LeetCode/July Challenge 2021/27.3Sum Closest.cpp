/* Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Constraints:

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4 */

// TC=O(n2) SC=O(1)
class Solution
{
public:
    int threeSumClosest(vector<int> &a, int x)
    {
        sort(a.begin(), a.end());
        int ans = a[0] + a[1] + a[2];
        for (int i = 0; i < a.size() - 2; i++)
        {
            int l = i + 1;
            int r = a.size() - 1;
            while (l < r)
            {
                long sum = a[i] + a[l] + a[r];
                if (abs(sum - x) < abs(ans - x))
                    ans = sum;
                else if (sum < x)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};