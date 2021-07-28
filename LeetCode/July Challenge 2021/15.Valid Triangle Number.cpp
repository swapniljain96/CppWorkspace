/*Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:
Input: nums = [4,2,3,4]
Output: 4
Constraints:
1 <= nums.length <= 1000
0 <= nums[i] <= 1000 */

// Valid Triangle Condition: " A + B > C "
// for this we first sort the array and apply 2 pointers technique for each i using l and r where l always start from 0 and
// r always start from i-1;
// eg. A = [1, 1, 1, 2, 2]
//          l        r  i

class Solution
{
public:
    int triangleNumber(vector<int> &a)
    {
        int n = a.size();
        if (n < 3)
            return 0;
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 2; i < n; i++)
        {
            int l = 0, r = i - 1;
            while (l < r)
            {
                if (a[l] + a[r] > a[i])
                {
                    ans += (r - l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};