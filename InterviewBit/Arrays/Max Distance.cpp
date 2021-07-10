/* Problem Description
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
Input Format
First and only argument is an integer array A.
Output Format
Return an integer denoting the maximum value of j - i;
Example Input
Input 1:
 A = [3, 5, 4, 2]
Example Output
Output 1:  2
Example Explanation
Explanation 1:
Maximum value occurs for pair (3, 4). */

// Method 1(a): Using leftmax and rightmax array TC=O(n)
int Solution::maximumGap(const vector<int> &A)
{
    int n = A.size();
    int Lmin[n], Rmax[n];

    Lmin[0] = A[0];
    for (int i = 1; i < n; i++)
        Lmin[i] = min(Lmin[i - 1], A[i]);

    Rmax[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        Rmax[i] = max(Rmax[i + 1], A[i]);

    int i = 0, j = 0, maxdiff = -1;

    while (i < n && j < n)
    {
        if (Lmin[i] <= Rmax[j])
        {
            maxdiff = max(maxdiff, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return maxdiff;
}
// Method 1(b): Using rightmax array only TC=O(n)
int Solution::maximumGap(const vector<int> &a)
{
    int n = a.size();
    int R[n];
    R[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        R[i] = max(R[i + 1], a[i]);
    }
    int i = 0, j = 0, dif = 0;
    while (i < n && j < n)
    {
        if (R[j] >= a[i])
        {
            dif = max(dif, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return dif;
}

// Method 2: Using sorting with vector pair and sorting  TC=O(nlogn)

int Solution::maximumGap(const vector<int> &A)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back(make_pair(A[i], i));
    }
    sort(v.begin(), v.end());
    int mini = INT_MAX, ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mini = min(mini, v[i].second);
        ans = max(ans, v[i].second - mini);
    }
    return ans;
}
