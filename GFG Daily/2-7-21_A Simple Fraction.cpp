// Given a fraction. Convert it into a decimal.
// If the fractional part is repeating, enclose the repeating part in parentheses.

// Example 1:

// Input: numerator = 1, denominator = 3
// Output: "0.(3)"
// Explanation: 1/3 = 0.3333... So here 3 is
// recurring.
// Example 2:

// Input: numerator = 5, denominator = 2
// Output: "2.5"
// Explanation: 5/2 = 2.5

class Solution
{
public:
    string fractionToDecimal(int num, int den)
    {
        int q = num / den;
        int r = num % den;
        string res;
        unordered_map<int, int> m;
        res += to_string(q);
        if (r == 0)
        {
            return res;
        }
        else
        {
            res += '.';
            while (r != 0)
            {
                if (m.find(r) != m.end())
                {
                    int pos = m[r];
                    res.insert(pos, "(");
                    res += ')';
                    break;
                }
                else
                {
                    m[r] = res.size();
                    r *= 10;
                    q = r / den;
                    r = r % den;
                    res += to_string(q);
                }
            }
        }
        return res;
    }
};