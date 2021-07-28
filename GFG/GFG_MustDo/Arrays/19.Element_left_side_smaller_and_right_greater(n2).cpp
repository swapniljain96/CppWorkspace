/* Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Example 1:

Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
Explanation:
Elements on left of 5 are smaller than 5
and on right of it are greater than 5.
 
Example 2:
Input:
N = 3
A[] = {11, 9, 12}
Output:
-1
 
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Constraints:
3 <= N <= 106
1 <= A[i] <= 106 */

int findElement(int a[], int n)
{
    int leftMax[n], rightMin[n];
    leftMax[0] = a[0];
    rightMin[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightMin[i] = min(rightMin[i + 1], a[i]);
    }

    for (int i = 1; i < n - 1; i++) //here extreme elements cannot be required element so start with 1 end at n-1
    {
        if (leftMax[i] == rightMin[i])
        {
            return a[i];
        }
    }
    return -1;
}