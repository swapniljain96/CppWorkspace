/* Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes an string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999 */

int romanToDecimal(string &str)
{
    int cnt = 0;
    int n = str.size();
    map<char, int> mp;
    mp.insert({'I', 1});
    mp.insert({'V', 5});
    mp.insert({'X', 10});
    mp.insert({'L', 50});
    mp.insert({'C', 100});
    mp.insert({'D', 500});
    mp.insert({'M', 1000});
    cnt = cnt + mp[str[n - 1]];
    for (int i = n - 2; i >= 0; i--)
    {
        if (mp[str[i + 1]] > mp[str[i]])
        {
            cnt = cnt - mp[str[i]];
        }
        else
        {
            cnt = cnt + mp[str[i]];
        }
    }
    return cnt;
}