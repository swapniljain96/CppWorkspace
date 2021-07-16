/* You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.
Example :
Input 1:
A = [1, 3, 2, 4, 5]
Return: [1, 2]
Input 2:
A = [1, 2, 3, 4, 5]
Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted. */

// Method 1:use another array sort it and with its help location of start and end
// TC=O(nlogn) SC=O(n)
vector<int> Solution::subUnsort(vector<int> &a)
{
    int n = a.size();
    vector<int> b(a);
    vector<int> ans;
    sort(b.begin(), b.end());
    if (a == b)
        return {-1};
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
        {
            r = i;
            break;
        }
    }
    return {l, r};
}

// Method 2: We can use the property that in sorted array, element at index i is smallest from index i to n-1.
// TC=O(n) SC=O(1)
vector<int> Solution::subUnsort(vector<int> &a)
{
    int n = a.size();
    int l = n, r = 0, mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mx)
            r = i;
        mx = max(mx, a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > mn)
            l = i;
        mn = min(mn, a[i]);
    }
    if (l == n)
        return {-1};
    return {l, r};
}
