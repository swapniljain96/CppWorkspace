/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

Follow-up: Could you solve the problem in linear time and in O(1) space? */

//  Method 1 (best)
class Solution
{
public:
    int majorityElement(vector<int> &a)
    {
        int cnt = 0;
        int maj;
        for (int x : a)
        {
            if (cnt == 0)
            {
                maj = x;
            }
            cnt += (maj == x) ? 1 : -1;
        }
        return maj;
    }
};

//  Method 2
class Solution
{
public:
    int majorityElement(vector<int> &a)
    {
        int cnt = 1;
        int maj = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == maj)
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    maj = a[i];
                    cnt = 1;
                }
            }
        }
        return maj;
    }
};