/* Problem Description
Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.
NOTE:
A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
Problem Constraints
3 <= N <= 105
1 <= A[i], B <= 108
Given array always contain a bitonic point.
Array A always contain distinct elements.
Input Format
First argument is an integer array A denoting the bitonic sequence.
Second argument is an integer B.
Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesn't exist in A return -1.
Example Input
Input 1:
 A = [3, 9, 10, 20, 17, 5, 1]
 B = 20
Input 2:
 A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
 B = 30
Example Output
Output 1:
 3
Output 2:
 -1
Example Explanation
Explanation 1:
 B = 20 present in A at index 3
Explanation 2:
 B = 30 is not present in A */

// Algo: first find the peak element then use binary search in left and right half from that peak
int findPeak(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return 0;
    if (a[0] > a[1])
        return 0;
    if (a[n - 1] > a[n - 2])
        return n - 1;
    int l = 1, r = n - 2;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid - 1] < a[mid] && a[mid] > a[mid + 1])
        {
            return mid;
        }
        else if (a[mid] < a[mid + 1])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return 0;
}
int bs(vector<int> &a, int x, int l, int h, int flag)
{
    while (l <= h)
    {
        int m = l + (h - l) / 2;
        if (a[m] == x)
            return m;
        else if (x < a[m])
        {
            if (flag)
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        else
        {
            if (flag)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
    }
    return -1;
}
int Solution::solve(vector<int> &a, int x)
{
    int n = a.size();
    int ind = findPeak(a);
    int lbs = bs(a, x, 0, ind, 1);         // binary search in increasing subArray
    int rbs = bs(a, x, ind + 1, n - 1, 0); // binary search in decreasing subArray
    return max(lbs, rbs);
}