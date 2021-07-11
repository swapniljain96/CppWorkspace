/* Given an index k, return the kth row of the Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
Example:
Input : k = 3
Return : [1,3,3,1]
NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space? */

// Method 1: By computing till that row
vector<int> Solution::getRow(int n)
{
    if (n == 0)
        return {1};
    if (n == 1)
        return {1, 1};
    if (n == 2)
        return {1, 2, 1};
    vector<vector<int>> v;
    v.push_back({1});
    v.push_back({1, 1});
    for (int i = 2; i <= n; i++)
    {
        vector<int> t;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                t.push_back(1);
            }
            else
            {
                t.push_back(v[i - 1][j - 1] + v[i - 1][j]);
            }
        }
        v.push_back(t);
    }
    return v[n];
}

// Method 2:By using formula
vector<int> Solution::getRow(int A)
{
    vector<int> res;
    long long num = 1;
    res.push_back(num);
    for (int i = 1; i <= A; i++)
    {
        num *= (A - i + 1);
        num /= i;
        res.push_back(num);
    }
    return res;
}