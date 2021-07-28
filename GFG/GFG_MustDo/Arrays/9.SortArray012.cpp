/* Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^6
0 <= A[i] <= 2 */

 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int l=0,mid=0,r=n-1;
        while(mid<=r)
        { if(a[mid]==0) 
          {swap(a[l],a[mid]);
             l++;
             mid++;
          }
          else if(a[mid]==1)
          { mid++;}
          else if(a[mid]==2)
          { swap(a[r],a[mid]);
            r--; 
          }
        }
    }
    
};
