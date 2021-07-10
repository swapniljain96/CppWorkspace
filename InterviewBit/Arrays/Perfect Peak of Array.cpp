/* Problem Description
Given an integer array A of size N.
You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.
If it exists return 1 else return 0.
NOTE:
Do not consider the corner elements i.e A[0] and A[N-1] as the answer.
Problem Constraints
3 <= N <= 105
1 <= A[i] <= 109
Input Format
First and only argument is an integer array A containing N integers.
Output Format
Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it else return 0.
Example Input
Input 1:
 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:
 A = [5, 1, 4, 4]
Example Output
Output 1:
 1
Output 2:
 0
Example Explanation
Explanation 1:
 A[4] = 6 is the element we are looking for.
 All elements on left of A[4] are smaller than it and all elements on right are greater.
Explanation 2:
 No such element exits. */

//Algo: to find this our element will be greater than max if left and smaller than min from right.
// e.g: a[]= [5, 1, 4, 3, 6, 8, 10, 7, 9]
//      L[]= [5 5 5 5 6 8 10 10 10]
//      R[]= [1 1 3 3 6 7 7 7 9]
//      so here for finding answer L[i-1]<a[i] and a[i]<R[i+1]
int Solution::perfectPeak(vector<int> &a)
{
    int n = a.size();
    int L[n], R[n];
    L[0] = a[0];
    R[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        L[i] = max(L[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        R[i] = min(R[i + 1], a[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (L[i - 1] < a[i] and a[i] < R[i + 1])
        {
            return 1;
        }
    }
    return 0;
}
