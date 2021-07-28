/* Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

Example 2:
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements 
from 1st position to 5th position
is 15.

Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N and S as input parameters and returns a list containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the list should be according to 1-based indexing. If no such subarray is found, return an array consisting only one element that is -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Ai <= 1010 */

class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int a[], int n, int s)
    {
        int sum = a[0];
        int i = 0, j = 1; //i and j give the starting and ending of the window
        vector<int> res;
        while (j <= n) //here = is imp bcoz n is not size of array it is upper limit of number
        {
            if (sum == s) //if pehle hi sum aa gaya toh aage check hi nahi krna
            {
                res.push_back(i + 1);
                res.push_back(j);
                return res;
            }
            else if (sum < s) //if sum is smaller than required sum then window ko increase karo (by doing j++)
            {
                sum += a[j++];
            }
            else if (sum > s) //if sum is larger than required sum then window ko decrease karo (by doing i++)
            {
                sum += a[i--];
            }
        }
        res.push_back(-1); //if given sum is not found then put -1 in vector and return it
        return res;
    }
};