/* Problem Description
Given a positive integer A, return its corresponding column title as appear in an Excel sheet.
Problem Constraints
1 <= A <= 1000000000
Input Format
First and only argument is integer A.
Output Format
Return a string, the answer to the problem.
Example Input
Input 1:
A = 1
Input 2:
 A = 28
Example Output
Output 1:
 "A"
Output 2:
 "AB"
Example Explanation
Explanation 1:
 1 -> A
Explanation 2:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB  */

//Method 1
string Solution::convertToTitle(int a)
{
    string ans = "";
    while (a > 0)
    {
        int c = a % 26;
        if (c == 0)
        {
            ans = 'Z' + ans;
            a = (a - 1) / 26;
        }
        else
        {
            ans = char(c + 64) + ans;
            a = a / 26;
        }
    }
    return ans;
}

//Method 2
string Solution::convertToTitle(int n)
{
    string ans = "";
    while (n)
    {
        ans = char((n - 1) % 26 + 'A') + ans;
        n = (n - 1) / 26;
    }
    return ans;
}
