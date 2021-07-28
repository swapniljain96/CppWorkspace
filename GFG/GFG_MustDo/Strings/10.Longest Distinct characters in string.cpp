/* Given a string S, find length of the longest substring with all distinct characters. 

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.
â€‹Example 2:

Input: 
S = "aaa"
Output: 3
Explanation: "a" is the longest substring 
with all distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestSubstrDitinctChars() which takes the string S as input and returns the length of the longest substring with all distinct characters.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K), where K is Constant.


Constraints:
1<=|S|<=105 */

int longestSubstrDitinctChars(string a)
{
    int n = a.size();
    set<char> s;
    int i = 0, j = 0;
    int ans = 0, cnt = 0;
    while (i < n && j < n)
    {
        if (s.find(a[j]) == s.end())
        {
            cnt++;
            s.insert(a[j]);
            ans = max(ans, cnt);
            j++;
        }
        else
        {
            cnt--;
            s.erase(a[i]);
            i++;
        }
    }
    return ans;
}