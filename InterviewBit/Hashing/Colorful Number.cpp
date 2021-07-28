/* For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1 */

int Solution::colorful(int A)
{
    unordered_map<int, int> m;
    int part = 1;
    while (A)
    {
        part = 1;
        int n = A;
        while (n)
        {
            part *= n % 10;
            if (m[part])
                return 0;
            m[part]++;
            n = n / 10;
        }
        A = A / 10;
    }
    return 1;
}