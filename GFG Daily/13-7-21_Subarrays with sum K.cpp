/* Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.
Example 1:
Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.

Example 2:
Input:
N = 6
Arr = {9, 4, 20, 3, 10, 5}
k = 33
Output: 2
Explaination: 
Subarrays : arr[0...2], arr[2...4] have sum
exactly equal to 33.
Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)
Constraints:
1 ≤ N ≤ 2*104
-103 ≤ Arr[i] ≤ 103
-107 ≤ k ≤ 107 */

class Solution
{
public:
    int findSubArraySum(int a[], int n, int K)
    {
        unordered_map<int, int> m;
        int res = 0;
        int currsum = 0;
        for (int i = 0; i < n; i++)
        {
            currsum += a[i];
            if (currsum == K)
                res++;
            if (m.find(currsum - K) != m.end())
                res += (m[currsum - K]);
            m[currsum]++;
        }
        return res;
    }
};