/* 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists. */

// Method 1

class Solution
{
public:
  vector<int> twoSum(vector<int> &a, int target)
  {
    map<int, int> m;
    vector<int> v;
    for (int i = 0; i < a.size(); i++)
    {
      m[a[i]] = i;
    }
    for (int i = 0; i < a.size(); i++)
    {
      if (m.find(target - a[i]) != m.end() and i != m[target - a[i]])
      {
        v.push_back(i);
        v.push_back(m[target - a[i]]);
        break;
      }
    }
    return v;
  }
};