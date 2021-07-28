/* Given two strings a and b. The task is to find if the string 'b' can be obtained by rotating another string 'a' by exactly 2 places.

Example 1:

Input:
a = amazon
b = azonam
Output: 1
Explanation: amazon can be rotated anti
clockwise by two places, which will make
it as azonam.
Example 2:

Input:
a = geeksforgeeks
b = geeksgeeksfor
Output: 0
Explanation: If we rotate geeksforgeeks by
two place in any direction , we won't get
geeksgeeksfor.
Your Task:
The task is to complete the function isRotated() which takes two strings as input parameters and checks if given strings can be formed by rotations. The function returns true if string 1 can be obtained by rotating string 2 by two places, else it returns false.

Expected Time Complexity: O(N).
Expected Auxilary Complexity: O(N).
Challenge: Try doing it in O(1) space complexity.

Constraints:
1 <= length of a, b < 100 */

class Solution
{
public:
    bool isRotated(string s1, string s2)
    {
        string ars = "", rs = "";

        if (s1.size() != s2.size())
            return false;
        if (s1.size() < 2)
        {
            return s1 == s2;
        }

        int len = s1.size();
        ars = ars + s1.substr(2, len) + s1.substr(0, 2);

        rs = rs + s1.substr(len - 2, len) + s1.substr(0, len - 2);

        return (s2 == rs || s2 == ars);
    }
};