/* Given an array of N integers. Find the first element that occurs K number of times. 
 

Example 1:

Input :
N = 7, K = 2
A[] = {1, 7, 4, 3, 4, 8, 7}
Output :
4
Explanation:
Both 7 and 4 occur 2 times. 
But 4 is first that occurs 2 times.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function firstElementKTime() which takes the array A[], its size N and an integer K as inputs and returns the required answer. If answer is not present in the array, return -1.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N, K <= 105
1<= A <= 106 */

class Solution
{
public:
    int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
            if (m[a[i]] == k)
            {
                return a[i];
            }
        }
        return -1;
    }
};