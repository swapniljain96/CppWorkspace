/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]


Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1 */

// Naive Approach TC=O(n) SC=O(n)
class Solution
{
public:
    void moveZeroes(vector<int> &a)
    {
        int n = a.size();
        vector<int> s(n);
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                s[j] = a[i];
                j++;
            }
        }
        a = s;
    }
};

// Optimal TC=O(n) SC=O(1)

class Solution
{
public:
    void moveZeroes(vector<int> &a)
    {
        int n = a.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                a[j] = a[i];
                j++;
            }
        }
        for (int i = j; i < n; i++) // bcoz instead of counting we just take that j value bcoz it the last index from of nonZeroIndex
        {
            a[i] = 0;
        }
    }
};