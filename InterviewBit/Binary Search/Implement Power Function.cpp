/* Implement pow(x, n) % d.
In other words, given x, n and d,
find (x^n % d)
Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.
Input : x = 2, n = 3, d = 3
Output : 2
2^3 % 3 = 8 % 3 = 2. */

// Algo:This is a classic problem: in order to computer the value of x raised to the nth power, you might start to consider first of all the case in which n is positive.
// https://leetcode.com/problems/powx-n/discuss/739646/C%2B%2B-Iterative-vs.-Recursive-Bitwise-Solutions-Explained-100-Time-80-space

/* Let's assume that n == 13, so we can say pow(x, 13) == pow(x, 1) * pow(x, 4) * pow(x, 8).
Looks familiar? We basically decomposed 13 in its binary digits (1101).
Okay, then: why would we care? Because that is how a computer efficiently gets powers: at each step we multiply x by itself, so we will get x(^1), x^2, x^4, x^8, x^16 and so on.
Starting to see the bits of the puzzle coming together now, now? We can decompose n as a binary number and then keep multiplying for x raised to some power of 2 value as we go along and - boom, the magic is done!
Okay now, but what about negative powers?
Well, instead of multiplying, we divide. Period.
No, really: it changes that little.
Iterative approach, easier to follow: */

#define ll long long int
int Solution::pow(int x, int n, int d)
{
    if (d == 1 || x == 0)
        return 0;
    ll ans = 1, y = x % d; //we already take x mod d in y
    while (n > 0)
    {
        if (n % 2)
            ans = ((ans)*y) % d; //if power n odd hai toh bas ek baar multiple krke mod lelo
        y = (y * y) % d;         //if power even hai toh we multiply with same number and take mod
        if (y < 0)
            y += d; //if y is less then d(mod value) then add d to y
        n /= 2;
    }
    if (ans < 0) //this if is use when we got negative numbers
    {
        ans = (d - abs(ans) % d);
    }
    return ans;
}
