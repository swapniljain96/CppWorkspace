/* You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,
A=[1, 3, -1]
f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5
So, we return 5. */

// Method 1: Naive approach TC=O(n2)
int f(vector<int> &a, int i, int j)
{
    return abs(a[i] - a[j]) + abs(i - j);
}

int Solution::maxArr(vector<int> &a)
{
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, f(a, i, j));
        }
    }
    return ans;
}

// Method 2:Using mod property TC=O(n)
int Solution::maxArr(vector<int> &A)
{
    int max1 = INT_MIN;
    int min1 = INT_MAX;
    int max2 = INT_MIN;
    int min2 = INT_MAX;
    for (int i = 0; i < A.size(); i++)
    {
        max1 = max(A[i] + i, max1);
        min1 = min(A[i] + i, min1);
        max2 = max(A[i] - i, max2);
        min2 = min(A[i] - i, min2);
    }
    return max(max1 - min1, max2 - min2);
}

// to understand better: https://www.youtube.com/watch?v=-O1kvmSBFvg
