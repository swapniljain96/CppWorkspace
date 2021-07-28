/* Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1. */

int Solution::lengthOfLongestSubstring(string a)
{
    unordered_set<char> s;
    int i = 0, j = 0, res = 0;
    while (j < a.size())
    {
        if (s.find(a[j]) == s.end())
        {
            s.insert(a[j]);
            j++;
        }
        else
        {
            s.erase(a[i]);
            i++;
        }
        res = max(res, j - i);
    }
    return res;
}
