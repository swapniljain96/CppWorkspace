/* Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.

Problem Constraints
1 <= |A|, |B| <= 1005

Input Format
First argument is an string A.

Second argument is an string B.
Output Format
Return the length of such longest common subsequence between string A and string B.

Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"

Example Output
Output 1:

 5
Example Explanation
Explanation 1:
The longest common subsequence is "bbcgf", which has a length of 5 */

int Solution::solve(string a, string b)
{
    int x = a.size();
    int y = b.size();
    int t[x + 1][y + 1];
    memset(t, 0, sizeof(t));
    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[x][y];
}
