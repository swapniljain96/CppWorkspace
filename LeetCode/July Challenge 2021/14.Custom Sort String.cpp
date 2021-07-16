/* order and str are strings composed of lowercase letters. In order, no letter occurs more than once.
order was sorted in some custom order previously. We want to permute the characters of str so that they match the order that order was sorted. More specifically, if x occurs before y in order, then x should occur before y in the returned string.
Return any permutation of str (as a string) that satisfies this property.
Example:
Input: 
order = "cba"
str = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
Note:
order has length at most 26, and no character is repeated in order.
str has length at most 200.
order and str consist of lowercase letters only. */

// Algo: keep the count of each character of given string in map, now traverse the order string from start
// and if its character is present in map then add it to result string and decrement count.
// and at last enter add the remaining characters from map.
class Solution
{
public:
    string customSortString(string order, string str)
    {
        unordered_map<char, int> m;
        for (int i = 0; i < str.size(); i++)
        {
            m[str[i]]++;
        }
        string s;
        for (int i = 0; i < order.size(); i++)
        {
            while (m[order[i]])
            {
                s = s + order[i];
                m[order[i]]--;
            }
        }
        for (auto x : m)
        {
            while (x.second)
            {
                s = s + x.first;
                x.second--;
            }
        }
        return s;
    }
};