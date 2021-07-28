/* Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)" */

string Solution::fractionToDecimal(int Num, int Den)
{
    if (Num == 0)
        return "0";
    string ans = "";

    // sign check
    if (Num < 0 ^ Den < 0) //bcoz 0 XOR 1 = 1 XOR 0 = 1 means(either - or + result to 1 of if condition)
        ans += '-';

    // remove the signs
    long N = abs(long(Num));
    long D = abs(long(Den));

    // the integer part is easy
    ans += to_string(N / D);

    // if there is no fractional part
    if (N % D == 0) 
        return ans;

    // adding decimal point
    ans += '.';

    // heart of the code (decimal part)
    unordered_map<int, int> M;
    long r = N % D;
    while (r != 0)
    {
        if (!M[r])
        {
            ans.insert(M[r], 1, '(');
            ans += ')';
            break;
        }

        M[r] = ans.size();

        r *= 10;
        ans += to_string(r / D);
        r %= D;
    }
    return ans;
}
