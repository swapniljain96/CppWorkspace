/* Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.

Problem Constraints
0 <= N <= 3000

-107 <= A[i] <= 107

Input Format
The first and the only argument contains an integer array A.

Output Format
Return an integer representing the answer as described in the problem statement.

Example Input
Input 1:

 A = [1, 2, 1]
Input 2:

 A = [1, 11, 2, 10, 4, 5, 2, 1]

Example Output
Output 1:

 3
Output 2:

 6

Example Explanation
Explanation 1:

 [1, 2, 1] is the longest subsequence.
Explanation 2:

 [1 2 10 4 2 1] is the longest subsequence. */

int Solution::longestSubsequenceLength(const vector<int> &A)
{
    int n = A.size();
    // corner cases
    if (n <= 1)
    {
        return n;
    }

    /*
        Logic:
        For each i calculate the longest increasing sub sequence from 0 - i
        and decreasing sequence from A.size() - 1 to i
        and then to get the final result chose the i which has the highest sum of
        both!
    */

    // Part 1
    vector<int> increasingDp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                increasingDp[i] = max(increasingDp[i], 1 + increasingDp[j]);
            }
        }
    }

    // Part 2
    vector<int> decreasingDp(n, 1);
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[i] > A[j])
            {
                decreasingDp[i] = max(decreasingDp[i], 1 + decreasingDp[j]);
            }
        }
    }

    // Calculating the overall result
    int result = 1;
    for (int i = 0; i < n; i++)
    {
        result = max(result, increasingDp[i] + decreasingDp[i]);
    }

    // i th element is counted twice
    return result - 1;
}