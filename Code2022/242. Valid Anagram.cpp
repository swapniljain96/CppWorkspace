/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters. */

class Solution
{
public:
    void calc(string s, vector<int> &freq)
    {
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
    }

    bool isAnagram(string s, string t)
    {
        vector<int> sf(26), tf(26);
        calc(s, sf);
        calc(t, tf);
        for (int i = 0; i < 26; i++)
        {
            if (sf[i] != tf[i])
            {
                return false;
            }
        }
        return true;
    }
};