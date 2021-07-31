/* Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.

Input Format
First argument is an string A.

Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.

Example Input
Input 1:

 A = "abcde"
Input 2:

 A = "abbaee"


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 No possible rearrangement to make the string palindrome.
Explanation 2:

 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome. */

//  Algo : play with frequency of characters present in the given string.
//         A palindrome string can contain a character with odd frequency only once.
//         If the given string have more than one character with odd frequency then we cannot make it palindrome

int Solution::solve(string A)
{
    unordered_map<char, int> m;
    int n = A.size();
    for (auto x : A)
        m[x]++;
    int odd = 0;
    for (auto x : m)
        if (x.second % 2)
            odd++;

    if (odd <= 1)
        return 1;
    return 0;
}
