/* Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104 */

// Brute Force TC: O(n)
class Solution
{
public:
    int searchInsert(vector<int> &a, int x)
    {
        int i = 0, n = a.size();
        for (; i < n - 1; i++)
        {
            if (a[i] == x)
                return i;
            else if (a[i] < x and x < a[i + 1])
                return i + 1;
        }
        if (a[i] == x)
            return i;
        if (a[i] < x)
            return n;
        return 0;
    }
};

// Optimized TC: O(logn)
class Solution
{
public:
    int searchInsert(vector<int> &a, int x)
    {
        int n = a.size();
        // if(x<a[0])return 0;   we can write it or skip it. in both case it works.
        // if(a[n-1]<x)return n;
        int l = 0, r = n - 1;
        int mid = l + (r - l) / 2;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (a[mid] == x)
                return mid;
            else if (a[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};