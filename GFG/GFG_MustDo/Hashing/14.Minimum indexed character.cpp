/* Given a string str and another string patt. Find the first position (considering 0-based indexing) of the character in patt that is present at the minimum index in str.


Example 1:

Input:
str = geeksforgeeks
patt = set
Output: 1
Explanation: e is the character which is
present in given patt "geeksforgeeks"
and is first found in str "set". First Position
of e in str is 1. 
Example 2:

Input:
str = adcffaet
patt = onkl
Output: -1
Explanation: There are none of the
characters which is common in patt
and str.

Your Task:
You only need to complete the function minIndexChar() that returns the index of answer in str or returns -1 in case no character of patt is present in str.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).


Constraints:
1 ≤ |str|,|patt| ≤ 105 */

class Solution
{
public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        set<char> s;
        for (char c : patt)
        {
            s.insert(c);
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (s.find(str[i]) != s.end())
                return i;
        }
        return -1;
    }