/* For some fixed n, an array nums is beautiful if it is a permutation of the integers 1, 2, ..., n, such that:

For every i < j, there is no k with i < k < j such that nums[k] * 2 = nums[i] + nums[j].

Given n, return any beautiful array nums.  (It is guaranteed that one exists.)

Example 1:

Input: n = 4
Output: [2,1,4,3]
Example 2:

Input: n = 5
Output: [3,1,2,5,4]

Note:
1 <= n <= 1000 */

// Algo: here the main catch is we have to make two separate arrays(for odd and even) from the previous array with the formula
//  Odd=2*elements[i]-1  ||  Even=2*elements[i] and after that merge odd and even array one after other.

class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        vector<int> v;
        v.push_back(1);
        while (v.size() < n)
        {
            vector<int> tmp;
            for (auto x : v)
            {
                if (2 * x - 1 <= n)
                    tmp.push_back(2 * x - 1);
            }
            for (auto x : v)
            {
                if (2 * x <= n)
                    tmp.push_back(2 * x);
            }
            v = tmp;
        }
        return v;
    }
};