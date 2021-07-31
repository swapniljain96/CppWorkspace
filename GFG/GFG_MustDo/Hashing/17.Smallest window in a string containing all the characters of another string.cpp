/* Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.
Example 2:

Input:
S = "zoomlazapzo"
P = "oza"
Output: 
apzo
Explanation: "apzo" is the smallest 
substring in which "oza" can be found.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as input paramters and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 ≤ |S|, |P| ≤ 105 */

class Solution
{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        int m[256] = {0};
        int ans = INT_MAX;
        int start = 0;
        int count = 0;
        for (int i = 0; i < t.length(); i++)
        {
            if (m[t[i]] == 0)
                count++;
            m[t[i]]++;
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
            return "-1";
    }
}
}
;