/* Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123
Output: 123

Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns 1..

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of S<=10 */

class Solution
{
public:
    int atoi(string s)
    {
        int sign = 1, res = 0, i = 0;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        while (s[i])
        {
            if (!(s[i] - '0' >= 0 and s[i] - '0' <= 9))
            {
                return -1;
            }
            res = res * 10 + s[i] - '0';
            i++;
        }
        return res * sign;
    }
};