/* Problem Description
Given a column title A as appears in an Excel sheet, return its corresponding column number.
Problem Constraints
1 <= |A| <= 100
Input Format
First and only argument is string A.
Output Format
Return an integer
Example Input
Input 1:

 1
Input 2:

 28

Example Output
Output 1:

 "A"
Output 2:

 "AB"
Example Explanation
Explanation 1:

 1 -> "A"
Explanation 2:

A  -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28  */

//Method l : using pow function and traverse in reverse order
int Solution::titleToNumber(string a)
{
    int ans = 0;
    int p = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        ans = ans + ((a[i] - 64) * pow(26, p++)); //a[i]-65+1=(a[i] - 64) gives the value of the character
    }                                             // like
    return ans;
}

//Method 2: using base value (by IB)
int Solution::titleToNumber(string a)
{
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans = ans * 26 + (a[i] - 'A' + 1);
    }
    return ans;
}
