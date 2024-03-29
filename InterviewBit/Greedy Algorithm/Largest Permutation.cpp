/* Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.

Problem Constraints
1 <= N <= 106

1 <= B <= 109

Input Format
First argument is an integer array A of size N.

Second argument is an integer B.

Output Format
Return an integer array denoting the largest lexicographical value array that can be created by executing atmost B swaps.
Example Input
Input 1:

 A = [1, 2, 3, 4]
 B = 1
Input 2:

 A = [3, 2, 1]
 B = 2


Example Output
Output 1:

 [4, 2, 3, 1]
Output 2:

 [3, 2, 1]


Example Explanation
Explanation 1:

 In one swap we can swap (1, 4) so that the array becomes : [4, 2, 3, 1].
Explanation 2:

 Array is already the largest lexicographical value array. */

vector<int> Solution::solve(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        mp[a[i]] = i;
    }
    for (int i = 0; i < n && k > 0; i++)
    {
        if (a[i] != n - i)
        {
            swap(mp[a[i]], mp[n - i]);
            swap(a[mp[a[i]]], a[i]);
            k--;
        }
    }
    return a;
}