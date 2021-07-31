/* Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string.

Example 1:

Input:
s = xyyz
Output: 1 
Explanation: Removing one 'y' will make 
frequency of each letter 1.

Example 2:

Input:
s = xxxxyyzz
Output: 0
Explanation: Frequency can not be made same 
same by removing just 1 character.

Your Task:  
You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.
Note: The driver code print 1 if the value returned is true, otherwise 0.


Expected Time Complexity: O(N) where N is length of str
Expected Auxiliary Space: O(1)


Constraints:
1 <= str.length() <= 104*/

class Solution
{
public:
    bool allSame(int m[])
    {
        int same;
        int i;
        for (i = 0; i < 26; i++)
        {
            if (m[i] > 0)
            {
                same = m[i];
                break;
            }
        }
        for (int j = i + 1; j < 26; j++)
            if (m[j] > 0 && m[j] != same)
                return false;
        return true;
    }

    bool sameFreq(string str)
    {
        int m[26] = {0};
        for (int i = 0; i < str.size(); i++)
            m[str[i] - 'a']++;
        if (allSame(m))
            return true;
        for (int i = 0; i < 26; i++)
        {
            if (m[i] > 0)
            {
                m[i]--;
                if (allSame(m))
                    return true;
                m[i]++;
            }
        }
        return false;
    }
};