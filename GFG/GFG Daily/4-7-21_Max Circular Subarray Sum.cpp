/* Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.
Example 1:
Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.
Example 2:
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1 <= N <= 106
-106 <= Arr[i] <= 106 */

class Solution
{
public:
    int circularSubarraySum(int a[], int n)
    {
        int mehmin = 0, mehmax = 0, msfmin = INT_MAX, msfmax = INT_MIN;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += a[i];
            mehmax = max(a[i], mehmax + a[i]);
            msfmax = max(msfmax, mehmax);
            mehmin = min(a[i], mehmin + a[i]);
            msfmin = min(msfmin, mehmin);
        }
        if (msfmax > 0)
            return max(msfmax, total - msfmin);
        return msfmax;
    }
};
