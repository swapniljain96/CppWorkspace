/* Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
Example 1:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]

Constraints:
1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104 */

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &a, int k, int x)
    {
        vector<int> v(a);
        vector<int> ans;
        vector<pair<int, int>> vp;
        for (int i = 0; i < v.size(); i++)
        {
            v[i] = abs(v[i] - x);
        }
        for (int i = 0; i < v.size(); i++)
        {
            vp.push_back({v[i], i});
        }
        sort(vp.begin(), vp.end());
        int i = 0;
        while (i < k)
        {
            ans.push_back(a[vp[i].second]);
            i++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};