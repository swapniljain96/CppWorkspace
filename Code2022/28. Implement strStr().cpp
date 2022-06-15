/* Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1


Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters. */

// * Naive TC=O(n2) SC=O(1)
class Solution
{
public:
    int strStr(string a, string b)
    {
        int nb = b.size();
        int na = a.size();
        for (int i = 0; i < na - nb + 1; i++)
        {
            if (a.substr(i, nb) == b)
            {
                return i;
            }
        }
        return -1;
    }
};