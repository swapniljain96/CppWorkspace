/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.
Assume that there will only be one solution
Example:
given array S = {-1 2 1 -4},
and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2) */

// TC=O(n2) SC=O(1)

int Solution::threeSumClosest(vector<int> &a, int x)
{
    sort(a.begin(), a.end());
    int ans = a[0] + a[1] + a[2];
    for (int i = 0; i < a.size() - 2; i++)
    {
        int l = i + 1;
        int r = a.size() - 1;
        while (l < r)
        {
            long sum = a[i] + a[l] + a[r];
            if (abs(sum - x) < abs(ans - x))
                ans = sum;
            else if (sum < x)
                l++;
            else
                r--;
        }
    }
    return ans;
}
