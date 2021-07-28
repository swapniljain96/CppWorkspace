/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2)  */

vector<vector<int>> Solution::threeSum(vector<int> &a)
{
    vector<vector<int>> v;
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (i != 0 and a[i] == a[i - 1])
            continue;
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            long long sum = 0LL + a[i] + a[l] + a[r]; //we can also use long long sum = (long long)a[i] + a[l] + a[r];
            if (sum == 0)                             // it is just a simple typecast to long long
            {
                v.push_back({a[i], a[l], a[r]});
                while (l < r && a[l] == a[l + 1])
                    l++;
                while (l < r && a[r] == a[r - 1])
                    r--;
                l++;
                r--;
            }
            else if (sum < 0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return v;
}
