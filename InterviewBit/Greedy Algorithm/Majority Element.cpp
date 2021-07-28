/* Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Example :3

Input : [2, 1, 2]
Return  : 2 which occurs 2 times which is greater than 3/2.*/

// Algo: For a number to be a majority number it should come more than 50% which means the count of that number is always +ve even if we
//       decrement the count of non majority number,so the last number with +ve count is the majority number.
// Suppose our 1st element is the majority element and traverse the array and update the count based on the condition.
// TC: O(n) SC : O(1)
int Solution::majorityElement(const vector<int> &a)
{
    int n = a.size();
    int cnt = 1;
    int m = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == m)
        {
            cnt++;
        }
        else
        {
            cnt--;
            if (cnt == 0)
            {
                m = a[i];
                cnt++;
            }
        }
    }
    return m;
}
