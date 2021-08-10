/* Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i. */

int Solution::minDistance(string a, string b)
{
    int x = a.size();
    int y = b.size();
    if (x == 0)
        return y;
    if (y == 0)
        return x;
    int t[x + 1][y + 1];
    memset(t, 0, sizeof(t));
    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = j;
            }
            else if (j == 0)
            {
                t[i][j] = i;
            }
            else if (a[i - 1] == b[j - 1])
            {
                t[i][j] = t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = 1 + min({t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]});
            }
        }
    }
    return t[x][y];
}
