/* Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.
Input Format:
The first and the only argument contains an integer, A.
Output Format:
Return a 2-d matrix of size A x A satisfying the spiral order.
Constraints:
1 <= A <= 1000
Examples:
Input 1:
    A = 3
Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]
Input 2:
    4
Output 2:
    [   [1, 2, 3, 4],
        [12, 13, 14, 5],
        [11, 16, 15, 6],
        [10, 9, 8, 7]   ] */

vector<vector<int>> Solution::generateMatrix(int n)
{
    vector<vector<int>> v;
    v.resize(n, vector<int>(n));
    int r = n;
    int c = n;
    int rstart = 0, cstart = 0, i = 0;
    int cnt = 1;
    while (rstart < r && cstart < c)
    {
        for (i = cstart; i < c; i++)
        {
            v[rstart][i] = cnt;
            cnt++;
        }
        rstart++;

        for (i = rstart; i < r; i++)
        {
            v[i][c - 1] = cnt;
            cnt++;
        }
        c--;

        if (rstart < r)
        {
            for (i = c - 1; i >= cstart; i--)
            {
                v[r - 1][i] = cnt;
                cnt++;
            }
            r--;
        }

        if (cstart < c)
        {
            for (i = r - 1; i >= rstart; i--)
            {
                v[i][cstart] = cnt;
                cnt++;
            }
            cstart++;
        }
    }
    return v;
}
