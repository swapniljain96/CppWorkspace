// An n-bit gray code sequence is a sequence of 2n integers where:

// Every integer is in the inclusive range [0, 2n - 1],
// The first integer is 0,
// An integer appears no more than once in the sequence,
// The binary representation of every pair of adjacent integers differs by exactly one bit, and
// The binary representation of the first and last integers differs by exactly one bit.
// Given an integer n, return any valid n-bit gray code sequence.

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> v;
        v.push_back(0);
        if (n == 0)
            return v;
        v.push_back(1);
        int cur = 1;
        for (int i = 2; i <= n; i++)
        {
            cur *= 2;
            for (int j = v.size() - 1; j >= 0; j--)
            {
                v.push_back(cur + v[j]);
            }
        }
        return v;
    }
};