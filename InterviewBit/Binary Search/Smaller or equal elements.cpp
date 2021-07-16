/* Problem Description

Given an sorted array A of size N. Find number of elements which are less than or equal to B.
NOTE: Expected Time Complexity O(log N)
Problem Constraints
1 <= N <= 106
1 <= A[i], B <= 109
Input Format
First agument is an integer array A of size N.
Second argument is an integer B.
Output Format
Return an integer denoting the number of elements which are less than or equal to B.
Example Input
Input 1:
 A = [1, 3, 4, 4, 6]
 B = 4
Input 2:
 A = [1, 2, 5, 5]
 B = 3

Example Output
Output 1:
 4
Output 2:
 2
Example Explanation
Explanation 1:
 Elements (1, 3, 4, 4) are less than or equal to 4.
Explanation 2:
 Elements (1, 2) are less than or equal to 3. */

//  Method 1: here we find the upper bound of the given number(x) using binary search.
int Solution::solve(vector<int> &a, int x)
{
    int pos = -1;
    int n = a.size();
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] <= x)
        {
            pos = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return pos + 1;
}

// Method 2: here we use C++ STL built-in function
int Solution::solve(vector<int> &a, int x)
{
    auto itr = upper_bound(a.begin(), a.end(), x);
    return itr - a.begin();
}