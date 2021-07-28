/* Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

Example 1:
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 
Note:

2 <= nums.length <= 30000
0 <= nums[i] <= 106
It is guaranteed there is at least one way to partition nums as described. */

class Solution
{
public:
    int partitionDisjoint(vector<int> &a)
    {
        int n = a.size();
        vector<int> lmax(n), rmin(n);
        lmax[0] = a[0];
        rmin[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            lmax[i] = max(lmax[i - 1], a[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            rmin[i] = min(rmin[i + 1], a[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (lmax[i] <= rmin[i + 1] && rmin[i] <= lmax[i + 1])
            {
                return i + 1;
            }
        }
        return 0;
    }
};