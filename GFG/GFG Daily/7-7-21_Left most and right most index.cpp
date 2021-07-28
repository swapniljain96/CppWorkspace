/* Given a sorted array with possibly duplicate elements. The task is to find indexes of first and last occurrences of an element X in the given array.

Note: If the element is not present in the array return {-1,-1} as pair.

Example 1:
Input:
N = 9
v[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}
X = 5
Output:
2 5
Explanation:
Index of first occurrence of 5 is 2
and index of last occurrence of 5 is 5.
Example 2:

Input:
N = 9
v[] = {1, 3, 5, 5, 5, 5, 7, 123, 125}
X = 7
Output:
6 6
Your Task:  
You don't need to read input or print anything. Your task is to complete the function indexes() which takes the array v[] and an integer X as inputs and returns  the first and last occurrence of the element X. If the element is not present in the array return {-1,-1} as pair.
Can you solve the problem in expected time complexity?
Expected Time Complexity: O(Log(N))
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 105
1 ≤ v[i], X ≤ 1018 */

class Solution
{
public:
    pair<long, long> indexes(vector<long long> v, long long x)
    {
        if (binary_search(v.begin(), v.end(), x))
        {
            int f = lower_bound(v.begin(), v.end(), x) - v.begin();
            int s = upper_bound(v.begin(), v.end(), x) - v.begin();
            return {f, s - 1};
        }
        return {-1, -1};
    }
};