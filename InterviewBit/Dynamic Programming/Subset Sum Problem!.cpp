/* Given an integer array A of size N.

You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

If there exist a subset then return 1 else return 0.

Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100

1 <= B <= 105

Input Format
First argument is an integer array A.

Second argument is an integer B.

Output Format
Return 1 if there exist a subset with sum B else return 0.

Example Input
Input 1:

 A = [3, 34, 4, 12, 5, 2]
 B = 9
Input 2:

 A = [3, 34, 4, 12, 5, 2]
 B = 30


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 There is a subset (4, 5) with sum 9.
Explanation 2:

 There is no subset that add up to 30. */

int Solution::solve(vector<int> &a, int b)
{
    int n = a.size();
    int t[n + 1][b + 1];
    memset(t, 0, sizeof(t));
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < b + 1; j++)
        {
            if (a[i - 1] <= b)
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][b];
}
    