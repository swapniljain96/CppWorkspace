/* Given a sorted array of integers A(0 based index) of size N, find the starting and ending position of a given integar B in array A.
Your algorithm’s runtime complexity must be in the order of O(log n).
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Input Format
The first argument given is the integer array A.
The second argument given is the integer B.
Output Format
Return an array of size 2, such that first element = starting position of B in A and second element = ending position of B in A, if B is not found in A return [-1, -1].
Constraints
1 <= N <= 10^6
1 <= A[i], B <= 10^9
For Example
Input 1:
    A = [5, 7, 7, 8, 8, 10]
    B = 8
Output 1:
    [3, 4]
Explanation 1:
    First occurence of 8 in A is at index 3
    Second occurence of 8 in A is at index 4
    ans = [3, 4]
Input 2:
    A = [5, 17, 100, 111]
    B = 3
Output 2:
    [-1, -1] */

// Method 1: by user defined binary search for find floor and ceil value
// TC=O(logn)
int fl(vector<int> &a, int x, char c)
{
    int n = a.size();
    int l = 0, r = n - 1;
    int res = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (c == 'l')
        {
            if (a[m] >= x)
            {
                res = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            if (a[m] <= x)
            {
                res = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }
    return res;
}
vector<int> Solution::searchRange(const vector<int> &b, int x)
{
    vector<int> a(b);
    if (!binary_search(a.begin(), a.end(), x))
    {
        return {-1, -1};
    }
    int lbs = fl(a, x, 'l');
    int rbs = fl(a, x, 'u');
    return {lbs, rbs};
}

// Method 2: using lower_bound and upper_bound function
// TC=O(logn)

vector<int> Solution::searchRange(const vector<int> &a, int x)
{
    if (!binary_search(a.begin(), a.end(), x))
    {
        return {-1, -1};
    }
    int l = lower_bound(a.begin(), a.end(), x) - a.begin();
    int u = upper_bound(a.begin(), a.end(), x) - a.begin();
    return {l, u - 1};
}
