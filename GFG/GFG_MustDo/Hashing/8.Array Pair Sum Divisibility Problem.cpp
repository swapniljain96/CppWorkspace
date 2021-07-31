/* Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function canPair() which takes array and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.
 

Expected Time Complexity: O(n)
Expected Space Complexity : O(n)
 

Constraints:
1 <= length of array <= 100000
1 <= elements of array <= 100000
1 <= k <= 100000 */

class Solution
{
public:
    bool canPair(vector<int> a, int k)
    {
        if (a.size() % 2 == 1)
            return false;
        unordered_map<int, int> m;
        for (auto x : a)
        {
            m[((x % k) + k) % k]++; //eveb run for -ve numbers
        }
        for (int i = 0; i < a.size(); i++)
        {
            int rem = ((a[i] % k) + k) % k;
            if (2 * rem == k)
            {
                if (m[rem] % 2 != 0)
                    return false;
            }
            else if (rem == 0)
            {
                if (m[rem] & 1)
                    return false;
            }
            else if (m[rem] != m[k - rem])
            {
                return false;
            }
        }
        return true;
    }
};