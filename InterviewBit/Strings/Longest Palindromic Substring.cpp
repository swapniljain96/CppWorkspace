/* Given a string S, find the longest palindromic substring in S.
Substring of string S:
S[i...j] where 0 <= i <= j < len(S)
Palindrome string:
A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
Incase of conflict, return the substring which occurs first ( with the least starting index ).
Example :
Input : "aaaabaaa"
Output : "aaabaaa" */

string Solution::longestPalindrome(string s)
{
    int n = s.size();
    if (n <= 1)
        return s;
    int start = 0, end = 0, maxl = 1;
    //ODD CASE
    for (int i = 0; i < n - 1; i++)
    {
        int l = i, r = i;
        while (l >= 0 and r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        int len = r - l - 1;
        if (len > maxl)
        {
            maxl = len;
            start = l + 1;
            end = r - 1;
        }
    }
    //EVEN CASE
    for (int i = 0; i < n - 1; i++)
    {
        int l = i, r = i + 1;
        while (l >= 0 and r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
                break;
        }
        int len = r - l - 1;
        if (len > maxl)
        {
            maxl = len;
            start = l + 1;
            end = r - 1;
        }
    }
    return s.substr(start, maxl);
}
