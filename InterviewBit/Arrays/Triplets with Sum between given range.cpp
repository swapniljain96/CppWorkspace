/* Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.
Example:
Given [0.6, 0.7, 0.8, 1.2, 0.4] ,
You should return 1 as
0.6+0.7+0.4=1.7
1<1.7<2
Hence, the output is 1.
O(n) solution is expected.
Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed. */
//Method 1:naive solution
int Solution::solve(vector<string> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && j != k && i != k)
                {
                    float num = stof(a[i]) + stof(a[j]) + stof(a[k]);
                    if (1 < num && num < 2)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

//Method 2:Sort then use 2 pointers technique
int Solution::solve(vector<string> &A)
{
    int n = A.size();
    if (n < 3)
        return 0;
    sort(A.begin(), A.end());
    int l = 0, r = n - 1;
    while (l < r - 1)
    {
        double s = stod(A[l]) + stod(A[l + 1]) + stod(A[r]);
        if (s >= 2)
            r = r - 1;
        else if (s < 1)
            l = l + 1;
        else
            return 1;
    }
    return 0;
}
