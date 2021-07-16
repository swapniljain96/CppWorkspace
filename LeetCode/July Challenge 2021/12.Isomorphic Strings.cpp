/* Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Example 1:
Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Constraints:
1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character. */
// Method : Here we have to take 2 maps to link the characters from both the string to each other. so that no two character
// can have more than 1 link
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int sn = s.size();
        int tn = t.size();
        unordered_map<char, char> sm; //maps from s to t
        unordered_map<char, char> tm; //maps from t to s
        for (int i = 0; i < sn; i++)
        {
            char sc = s[i];
            char tc = t[i];
            if (sm[sc])
            {
                if (sm[sc] != tc)
                {
                    return false;
                }
            }
            if (tm[tc])
            {
                if (tm[tc] != sc)
                {
                    return false;
                }
            }
            sm[s[i]] = t[i];
            tm[t[i]] = s[i];
        }
        return true;
    }
};