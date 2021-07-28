/* There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1] */

// Method 1: by using 2 extra vector
int Solution::candy(vector<int> &a)
{
    int n = a.size();
    vector<int> L(n, 1), R(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
            L[i] = L[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            R[i] = R[i + 1] + 1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(L[i], R[i]);
    }
    return sum;
}

// Method 2: by using 1 extra vector

int Solution::candy(vector<int> &A)
{
    int n = a.size();
    vector<int> ans(n, 1);

    for (int i = 1; i < n; i++)
    {

        if (A[i] > A[i - 1])
            ans[i] = 1 + ans[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {

        if (A[i] > A[i + 1])
            ans[i] = max(ans[i], 1 + ans[i + 1]);
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {

        sum = sum + ans[i];
    }

    return sum;
}
