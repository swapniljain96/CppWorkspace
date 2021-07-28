/* Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything.Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity: O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).

Note: |s| represents the length of string s.

Constraints:
1 ≤ |a|,|b| ≤ 105 */

// Method 1: sort both strings and compare them.
class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        if (a.size() != b.size())
        {
            return false;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }
};

// Method 2: using extra space.
class Solution
{
public:
    bool isAnagram(string a, string b)
    {
        int arr[26];
        for (int i = 0; i < 26; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == ' ')
            {
                continue;
            }
            arr[(int)a[i] - 97]++;
        }

        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] == ' ')
            {
                continue;
            }
            arr[(int)b[i] - 97]--;
            if (arr[(int)b[i] - 97] < 0)
            {
                return false;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};