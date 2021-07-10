/* Given the array of strings A,you need to find the longest string S which is the prefix of ALL the strings in the array.
Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
and S2.
For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
Input Format
The only argument given is an array of strings A.
Output Format
Return longest common prefix of all strings in A.
For Example
Input 1:
    A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1:
    "a"
    Explanation 1:
        Longest common prefix of all the strings is "a".
Input 2:
    A = ["abab", "ab", "abcd"];
Output 2:
    "ab"
Explanation 2:
Longest common prefix of all the strings is "ab". */

string Solution::longestCommonPrefix(vector<string> &a)
{
    sort(a.begin(), a.end()); //here sort the array
    string ans = "";          //after sort we have to check for only 1st and last string, how many of characters
    int n = a.size();         // from start are equal and return it
    for (int i = 0, j = 0; i < a[0].size() && j < a[n - 1].size(); i++, j++)
    {
        if (a[0][i] == a[n - 1][j])
        {
            ans += a[0][i];
        }
    }
    return ans;
}
