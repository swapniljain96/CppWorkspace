/* Given an array of integers A and an integer B.

Find the total number of subarrays having exactly B odd numbers.

Problem Constraints
1 <= length of the array <= 105

1 <= A[i] <= 109

0 <= B <= A

Input Format
The first argument given is the integer array A.
The second argument given is integer B.

Output Format
Return the total number of subarrays having exactly B odd numbers.
Example Input
Input 1:

 A = [4, 3, 2, 3, 4]
 B = 2
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 3


Example Output
Output 1:
 4
Output 2:
 1
Example Explanation
Explanation 1:

The subarrays having exactly B odd numbers are:
[4, 3, 2, 3], [4, 3, 2, 3, 4], [3, 2, 3], [3, 2, 3, 4]
Explanation 2:

The subarrays having exactly B odd numbers is [5, 6, 7, 8, 9] */

// Method 1: After some modification it's just find number of sub-arrays with sum B and the modifications are:
// We treat the array value as 1 if it is odd and 0 if it is even. Now this problem is reduced to find the number of subarrays in the
// new array with sum equal to B.
// TC: O(n) SC: O(n)
int Solution::solve(vector<int> &A, int B)
{
    int sum = 0, count = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        sum += (A[i] % 2 ? 1 : 0); // or we can use sum+=A[i]%2; bcoz even number give zero value and odd number give 1 value
        if (sum == B)
        {
            count++;
        }
        if (m[sum - B])
        {
            count += m[sum - B];
        }
        m[sum]++;
    }
    return count;
}

// Method 2:If we subtract the number of subarrays with odd count<=k-1 from the number of subarrays with odd count<=k,
// we'll get the number of subarrays with odd count=k
// TC: O(n) SC: O(1)

int helper(vector<int> &v, int k)
{
    int j = 0, ans = 0, oddCount = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] % 2 != 0) //means number is odd
        {
            oddCount++;
        }
        while (j <= i && oddCount > k)
        {
            if (v[j] % 2 != 0) //means number is odd
            {
                oddCount--;
            }
            j++;
        }                   //here we have sliding window where i is end of the window and j is start of the window
        ans += (i - j + 1); //i-j+1 is the number of subarrays with odd count=k
    }
    return ans;
}
int Solution::solve(vector<int> &A, int B)
{
    return helper(A, B) - helper(A, B - 1);
}
