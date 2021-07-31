/* Given an integer array A of size N containing 0's and 1's only.

You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.

Problem Constraints
1 <= N <= 105

Input Format
First and only argument is an integer array A of size N.

Output Format
Return an integer denoting the longest length of the subarray.

Example Input
Input 1:

 A = [0, 1, 1, 0, 0, 1]
Input 2:

 A = [1, 0, 0, 1, 0]


Example Output
Output 1:

 5
Output 2:

 1


Example Explanation
Explanation 1:

 Subarray of length 5, index 1 to 5 i.e 1, 1, 0, 0, 1. Count of 1 = 3, Count of 0 = 2.
Explanation 2:

 Subarray of length 1 will be only subarray that follow the above condition. */

// Algo: Problems boils down to finding the longest subarray having sum=1 with some modification like take 0 as -1 in the array.

int Solution::solve(vector<int> &A)
{
    unordered_map<int, int> m;
    int sum = 0, max_len = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        //We will change the zeros to -1 for ease
        // Now this problem has reduced to find the largest subarray with sum 1
        sum += (A[i] == 0 ? -1 : 1);
        if (sum == 1)
        {
            max_len = max(max_len, i + 1);
        }
        if (m.find(sum) == m.end()) // that sum is not present in the map
        {
            m[sum] = i;
        }
        if (m.find(sum - 1) != m.end()) // means sum-1 is present in the map
        {
            max_len = max(max_len, i - m[sum - 1]);
        }
    }
    return max_len;
}