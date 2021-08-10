/* Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints
1 <= |A| <= 1005

Input Format
First and only argument is an string A.

Output Format
Return a integer denoting the length of longest palindromic subsequence in A.

Example Input
Input 1:

A = "bebeeed"

Example Output
Output 1:

4

Example Explanation
Explanation 1:

 The longest common pallindromic subsequence is "eeee", which has a length of 4 */

int Solution::solve(string s)
{
    string r = s;
    reverse(begin(r), end(r));
    int n = s.size();
    int t[n + 1][n + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[i - 1] == r[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][n];
}
