// We are given an array `nums` of positive integers, and two positive integers `left` and `right` (`left <= right`).

// Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least `left` and at most `right`.
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &a, int left, int right)
    {
        int res = 0, start = 0, end = 0, winCnt = 0;
        while (end < a.size())
        {
            if (left <= a[end] and a[end] <= right)
            {
                winCnt = end - start + 1;
            }
            else if (a[end] > right)
            {
                winCnt = 0;
                start = end + 1;
            }
            res += winCnt;
            end++;
        }
        return res;
    }
};