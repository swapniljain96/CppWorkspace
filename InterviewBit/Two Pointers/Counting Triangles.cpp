/* You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4 */

// Valid Triangle Condition: " A + B > C "
// for this we first sort the array and apply 2 pointers technique for each i using l and r where l always start from 0 and
// r always start from i-1;
// eg. A = [1, 1, 1, 2, 2]
//          l        r  i

int Solution::nTriang(vector<int> &a)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int mod = 1000000007;
    if (n < 3)
        return 0;
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        int l = 0;
        int r = i - 1;
        while (l < r)
        {
            if (a[r] + a[l] > a[i])
            {
                ans += (r - l);
                r--;
            }
            else
            {
                l++;
            }
            ans = ans % mod;
        }
    }
    return ans;
}
