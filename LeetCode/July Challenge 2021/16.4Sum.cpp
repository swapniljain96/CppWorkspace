/* Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
Constraints:
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
 */
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &a, int x)
    {
        int n = a.size();
        if (n < 4)
            return {};
        vector<vector<int>> v;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++)
        {
            if (i != 0 and a[i] == a[i - 1])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (j != i + 1 and a[j] == a[j - 1])
                    continue;
                int l = j + 1, r = n - 1;
                while (l < r)
                {
                    int sum = a[i] + a[j] + a[l] + a[r];
                    if (sum < x)
                    {
                        l++;
                    }
                    else if (sum > x)
                    {
                        r--;
                    }
                    else
                    {
                        v.push_back({a[i], a[j], a[l], a[r]});
                        while (l < r and a[l] == a[l + 1])
                            l++;
                        while (r > l and a[r] == a[r - 1])
                            r--;
                        l++;
                        r--;
                    }
                }
            }
        }
        return v;
    }
};