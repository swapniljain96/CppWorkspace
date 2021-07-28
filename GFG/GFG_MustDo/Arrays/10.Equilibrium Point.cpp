/* Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input:
n = 1
A[] = {1}
Output: 1
Explanation: Since its the only 
element hence its the only equilibrium 
point. 
Example 2:

Input:
n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case 
equilibrium point is at position 3 
as elements before it (1+3) = 
elements after it (2+2).
 

Your Task:
The task is to complete the function equilibriumPoint() which takes the array and n as input parameters and returns the point of equilibrium. Return -1 if no such point exists.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
1 <= A[i] <= 108 */

class Solution
{
public:
  // Method 1 by creating 2 arrays (1) that take sum from L->R (2)) that take sum from R->L
  int equilibriumPoint(long long a[], int n)
  {
    int L[n], R[n];
    L[0] = a[0];
    R[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
      L[i] = L[i - 1] + a[i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
      R[i] = R[i + 1] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
      if (R[i] == L[i])
      {
        return i + 1;
      }
    }
    return -1;
  }

  // Method 2 by creating 1 array and equationg sum
  int equilibriumPoint(long long a[], int n)
  {
    int L[n], R[n];
    L[0] = a[0];
    for (int i = 1; i < n; i++)
    {
      L[i] = L[i - 1] + a[i];
    }
    int leftSum, rightSum, totalSum = L[n - 1];
    for (int i = 0; i < n; i++)
    {
      leftSum = L[i] - a[i];
      rightSum = totalSum - L[i];
      if (leftSum == rightSum)
      {
        return i + 1;
      }
    }
    return -1;
  }
};