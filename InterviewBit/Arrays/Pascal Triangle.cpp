/* Given numRows, generate the first numRows of Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
Example:
Given numRows = 5,
Return
[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
] */

vector<vector<int>> Solution::solve(int n)
{
    if (n == 0)
        return {};
    if (n == 1)
        return {{1}};
    if (n == 2)
        return {{1}, {1, 1}};
    vector<vector<int>> v;
    v.push_back({1});
    v.push_back({1, 1});
    for (int i = 2; i < n; i++)
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
    return v;
}
