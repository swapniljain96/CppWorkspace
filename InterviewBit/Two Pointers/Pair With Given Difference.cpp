/* Problem Description
Given an one-dimensional unsorted array A containing N integers.
You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.
Return 1 if any such pair exists else return 0.
Problem Constraints
1 <= N <= 105
-103 <= A[i] <= 103
-105 <= B <= 105
Input Format
First argument is an integer array A of size N.
Second argument is an integer B.
Output Format
Return 1 if any such pair exists else return 0.
Example Input
Input 1:
 A = [5, 10, 3, 2, 50, 80]
 B = 78
Input 2:
 A = [-10, 20]
 B = 30
Example Output
Output 1:
 1
Output 2:

 1
Example Explanation
Explanation 1:
Pair (80, 2) gives a difference of 78.
Explanation 2:
Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30 */

// Method 1: using 2 pointers
// TC=O(nlogn) SC=O(1)
int Solution::solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int i = 0, j = 0;
    while (i < A.size() && j < A.size())
    {
        if (A[j] - A[i] == B && i != j)
        {
            return 1;
        }
        else if (A[j] - A[i] < B)
            j++;
        else
            i++;
    }
    return 0;
}

// Method 2: using binary search
// TC=O(nlogn) SC=O(1)
int Solution::solve(vector<int> &a, int x)
{
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++)
    {
        int find;
        if (a[i] <= x)
            find = a[i] + x;
        else
            find = a[i] - x;
        if (binary_search(a.begin() + i + 1, a.end(), find))
        {
            return 1;
        }
    }
    return 0;
}

// Method 3(a): using map (Y-X=B); or Y=X+B;
// TC=O(n) SC=O(n)
int Solution::solve(vector<int> &A, int B)
{
    map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        if (m[A[i]]) // we check if any Y is there in map that means there is a pair in the given array
            return 1;
        else
        {
            m[A[i] - B]++; //here we create map entry for both X-B and X+B
            m[A[i] + B]++;
        }
    }

    return 0;
}

// Method 3(b): using map
// TC=O(n) SC=O(n)
int Solution::solve(vector<int> &A, int B)
{
    unordered_map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        m[A[i]] = i;
    }
    for (auto it : A)
    {
        if (m.find(it + B) != m.end() && m[it + B] != m[it])
        {
            return 1;
        }
    }
    return 0;
}