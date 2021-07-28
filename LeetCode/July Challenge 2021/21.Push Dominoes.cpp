/* There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.

Example 2:
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."

Constraints:
n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'. */

class Solution
{
public:
    string pushDominoes(string s)
    {
        int n = s.size();
        vector<int> lf(n), rf(n);
        int nearL = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'L')
            {
                nearL = i;
            }
            else if (s[i] == 'R')
            {
                nearL = -1;
            }
            lf[i] = nearL;
        }
        int nearR = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                nearR = -1;
            }
            else if (s[i] == 'R')
            {
                nearR = i;
            }
            rf[i] = nearR;
        }
        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '.')
            {
                int leftdiff = lf[i] == -1 ? INT_MAX : abs(lf[i] - i);
                int rightdiff = rf[i] == -1 ? INT_MAX : abs(rf[i] - i);
                if (leftdiff == rightdiff)
                {
                    res += '.';
                }
                else if (leftdiff < rightdiff)
                {
                    res += 'L';
                }
                else
                {
                    res += 'R';
                }
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};