/* Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.

Problem Constraints
1 <= |A| <= 40000
1 <= A[i] <= |A|
1 <= B <= |A|

Input Format
The first argument given is the integer array A.
The second argument given is an integer B.

Output Format
Return an integer denoting the number of good subarrays of A.

Example Input
Input 1:
 A = [1, 2, 1, 2, 3]
 B = 2
Input 2:

 A = [1, 2, 1, 3, 4]
 B = 3

Example Output
Output 1:
 7
Output 2:
 3
Example Explanation
Explanation 1:
  Subarrays formed with exactly 2 different integers: [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 1, 2].
Explanation 2:
  Subarrays formed with exactly 3 different integers: [1, 2, 1, 3], [2, 1, 3], [1, 3, 4]. */

// Method 1: Here we asked to find out subarrays with k distinct integers inside it ,
//           so we can approach like subarrays with atmost k integers - subarrays with atmost (k-1) integers .
//           So we will get the Subarrays with exact k integers inside it.

int sol(vector<int> &A, int B)   //this function solve() gives the number of subarrays with atmost k distinct integers inside it.
{
    unordered_map<int, int> m;
    int res = 0;
    int i = 0;
    for (int j = 0; j < A.size(); j++)
    {
        m[A[j]]++;
        while (m.size() > B)
        {
            m[A[i]]--;
            if (m[A[i]] == 0)
            {
                m.erase(A[i]);
            }
            i++;
        }
        res += (j - i + 1);
    }
    return res;
}

int Solution::solve(vector<int> &a, int k)
{
    return sol(a, k) - sol(a, k - 1);
}
