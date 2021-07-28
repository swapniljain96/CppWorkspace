/* Your task is to implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting the first occurrence of the string x in s (0 based indexing).

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
s = GeeksForGeeks, x = Fr
Output: -1
Explanation: Fr is not present in the
string GeeksForGeeks as substring.
 

Example 2:

Input:
s = GeeksForGeeks, x = For
Output: 5
Explanation: For is present as substring
in GeeksForGeeks from index 5 (0 based
indexing).
 

Your Task:
You don't have to take any input. Just complete the strstr() function which takes two strings str, target as an input parameter. The function returns -1 if no match if found else it returns an integer denoting the first occurrence of the x in the string s.

Expected Time Complexity: O(|s|*|x|)
Expected Auxiliary Space: O(1)

Note : Try to solve the question in constant space complexity.

Constraints:
1 <= |s|,|x| <= 100 */

// Method 1
int strstr(string s, string x)
{
    int index;
    while ((index = s.find(x, 0)) != string::npos)
    {
        break;
    }
    return index;
}

// Method 2
int strstr(string s, string x)
{
    int S = x.size();
    int L = s.size();

    for (int i = 0; i <= L - S; i++)
    {
        int j;
        for (j = 0; j < S; j++)
        {
            if (s[i + j] != x[j])
                break;
        }
        if (j == S)
        {
            return i;
        }
    }
    return -1;
}

//Method 3
int strstr(string s, string x)
{
    int counter = 0;
    int i = 0;
    for (; i < s.size(); i++)
    {
        if (counter == x.size())
            break;
        if (x[counter] == s[i])
        {
            counter++;
        }
        else
        {
            //Special case where character preceding the i'th character is duplicate
            if (counter > 0)
            {
                i -= counter;
            }
            counter = 0;
        }
    }
    return counter < x.size() ? -1 : i - counter;
}