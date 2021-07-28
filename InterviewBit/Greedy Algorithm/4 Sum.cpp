/* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

 Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k]) */

// Method 1:Using SET here we have to use set becoz we have to return the answer in the lexicographically ordered way,which we can do by using a set.
// TC=O(n) SC=O(n)
vector<vector<int>> Solution::fourSum(vector<int> &A, int target)
{
    sort(A.begin(), A.end());
    set<vector<int>> res;
    int n = A.size();
    for (int i = 0; i < n - 3; ++i)
    {
        for (int j = i + 1; j < n - 2; ++j)
        {
            int st = j + 1;
            int end = n - 1;
            while (st < end)
            {
                int summ = A[i] + A[j] + A[st] + A[end];
                if (summ == target)
                {
                    res.insert({A[i], A[j], A[st], A[end]});
                    st++;
                    end--;
                }
                else if (summ < target)
                {
                    st++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
    vector<vector<int>> ans;
    for (auto i : res)
    {
        ans.push_back(i);
    }
    return ans;
}

// Method 2: using 4 pointers.
// TC=O(n) SC=O(1)
vector<vector<int>> Solution::fourSum(vector<int> &a, int x)
{
    int n = a.size();
    if (n < 4)
        return {};
    vector<vector<int>> v;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (i != 0 and a[i] == a[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 and a[j] == a[j - 1])
                continue;
            int l = j + 1, r = n - 1;
            while (l < r)
            {
                int sum = a[i] + a[j] + a[l] + a[r];
                if (sum < x)
                {
                    l++;
                }
                else if (sum > x)
                {
                    r--;
                }
                else
                {
                    v.push_back({a[i], a[j], a[l], a[r]});
                    while (l < r and a[l] == a[l + 1])
                        l++;
                    while (l < r and a[r] == a[r - 1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
    }
    return v;
}