/* Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.

Example 2:

Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018 */

class Solution
{

public:
    //Method 1 by swapping
    void reverseInGroups(vector<long long> &a, int n, int k)
    {
        for (int i = 0; i < n; i = i + k)
        {
            int l = i;
            int r = min(i + k - 1, n - 1); //min liya bcoz last wala group agar complete na bane toh array index out of bound aa jayega
            while (l < r)                  // imp we will swap till half of the array
            {
                swap(a[l], a[r]);
                l++;
                r--;
            }
        }
    }

    //Method 2 by reversing
    void reverseInGroups(vector<long long> &a, int n, int k)
    {
        for (int i = 0; i < n; i = i + k)
        {
            int l = i;
            int r = min(i + k, n);
            reverse(a.begin() + l, a.begin() + r);
        }
    }
};
