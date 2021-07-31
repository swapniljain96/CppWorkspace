/* Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and returns an array containing all the quadruples in a lexicographical manner. Also note that all the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.  (In the output each quadruple is separate by $. The printing is done by the driver's code)

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= N <= 100
-1000 <= K <= 1000
-100 <= A[] <= 100 */

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &a, int target)
    {
        set<vector<int>> ans;
        int n = a.size();
        sort(a.begin(), a.end());
        int sum;
        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 and a[i] == a[i - 1])
                continue; //Skip same values for index i to avoid duplicates
            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 and a[j] == a[j - 1])
                    continue; //Skip same values for index j to avoid duplicates
                int left = j + 1, right = n - 1;
                while (left < right)
                { //2 pointer technique
                    sum = a[i] + a[j] + a[left] + a[right];
                    if (sum == target)
                    {
                        ans.insert({a[i], a[j], a[left], a[right]});
                        left++;
                        right--;
                    }
                    else if (sum > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        vector<vector<int>> res;
        for (auto it : ans)
            res.push_back(it);
        return res;
    }
};