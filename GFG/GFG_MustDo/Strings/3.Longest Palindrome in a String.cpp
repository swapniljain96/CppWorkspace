/* Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).

Example 1:
Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.

Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 103 */

string longestPalin(string s)
{
    if (s.size() <= 1)
        return s;
    int maxl = 1;
    int n = s.size();
    int st = 0, en = 0;

    //odd length
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        int len = r - l - 1;
        if (len > maxl)
        {
            maxl = len;
            st = l + 1;
            en = r - 1;
        }
    }

    //even length
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i + 1;
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        int len = r - l - 1;
        if (len > maxl)
        {
            maxl = len;
            st = l + 1;
            en = r - 1;
        }
    }

    return s.substr(st, maxl);
}