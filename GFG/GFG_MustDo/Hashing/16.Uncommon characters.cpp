/* Given two strings A and B. Find the characters that are not common in the two strings. 

Example 1:

Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.
Example 2:

Input:
A = characters
B = alphabets
Output: bclpr
Explanation: The characters 'b','c','l','p','r' 
are either present in A or B, but not in both.

Your Task:  
You dont need to read input or print anything. Complete the function UncommonChars() which takes strings A and B as input parameters and returns a string that contains all the uncommon characters in sorted order. If no such character exists return "-1".


Expected Time Complexity: O(M+N) where M and N are the sizes of A and B respectively.
Expected Auxiliary Space: O(M+N)  


Constraints:
1<= M,N <= 104
String may contain duplicate characters. */

class Solution
{
public:
    string UncommonChars(string a, string b)
    {
        set<char> sa;
        set<char> sb;
        string ans = "";

        for (auto c : a)
        {
            sa.insert(c);
        }

        for (auto c : b)
        {
            sb.insert(c);
        }

        for (auto c : sa)
        {
            if (sb.find(c) == sb.end())
                ans += c;
        }

        for (auto c : sb)
        {
            if (sa.find(c) == sa.end())
                ans += c;
        }
        if (ans.size() == 0)
            return "-1";
        sort(ans.begin(), ans.end());
        return ans;
    }
};