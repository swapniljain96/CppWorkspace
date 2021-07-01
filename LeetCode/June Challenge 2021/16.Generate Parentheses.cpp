// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
class Solution
{
public:
    void solve(int open, int close, string op, vector<string> &v)
    {
        if (!open and !close)
        {
            v.push_back(op);
            return;
        }
        if (open != 0)
        {
            string op1 = op;
            op1.push_back('(');
            solve(open - 1, close, op1, v);
        }
        if (close > open)
        {
            string op1 = op;
            op1.push_back(')');
            solve(open, close - 1, op1, v);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> v;
        int open = n, close = n;
        string op = "";
        solve(open, close, op, v);
        return v;
    }
};