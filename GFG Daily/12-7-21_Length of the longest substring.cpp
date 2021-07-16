/* Given a string S, find the length of the longest substring without repeating characters.


Example 1:

Input:
S = "geeksforgeeks"
Output:
7
Explanation:
Longest substring is
"eksforg".
Example 2:

Input:
S = "abdefgabef"
Output:
6
Explanation:
Longest substring are
"abdefg" , "bdefga" and "defgab". */

class Solution
{
public:
    int longestUniqueSubsttr(string str)
    {
        int n = str.size();
        int res = 0;
        vector<int> m(256, -1);
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            i = max(i, m[str[j]] + 1);
            res = max(res, j - i + 1);
            m[str[j]] = j;
        }
        return res;
    }
};