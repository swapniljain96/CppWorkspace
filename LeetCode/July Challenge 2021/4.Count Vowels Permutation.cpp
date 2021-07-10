/* Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.
Example 1:
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
Constraints:
1 <= n <= 2 * 10^4 */

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        int mod = 1e9 + 7;
        for (int j = 2; j <= n; j++)
        {
            long A = (e + u + i) % mod;
            long E = (a + i) % mod;
            long I = (e + o) % mod;
            long O = i % mod;
            long U = (o + i) % mod;
            a = A;
            e = E;
            i = I;
            o = O;
            u = U;
        }
        return (a + e + i + o + u) % mod;
    }
};