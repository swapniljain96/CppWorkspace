/* Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ). */

string Solution::minWindow(string s, string p)
{
    int m[256] = {0};
    int ans = INT_MAX;
    int start = 0;
    int count = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if (m[p[i]] == 0)
            count++;
        m[p[i]]++;
    }
    int i = 0;
    int j = 0;
    while (j < s.length())
    {
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        if (count == 0)
        {
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;
                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "";
}
