/* Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Example :
Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.
You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow. */

// Method 1: using bucketing TC=O(n) SC=O(n)
int Solution::maximumGap(const vector<int> &a)
{
    int n = a.size();
    if (n < 2)
        return 0;
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());
    int nbuck = (mx - mn + n - 2) / (n - 1); //ceil value
    vector<int> minbuck(n - 1, INT_MAX);
    vector<int> maxbuck(n - 1, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        if (a[i] == mn || a[i] == mx)
            continue;
        int id = (a[i] - mn) / nbuck;
        minbuck[id] = min(minbuck[id], a[i]);
        maxbuck[id] = max(maxbuck[id], a[i]);
    }
    int ans = 0;
    int max_prev = mn;
    for (int i = 0; i < n - 1; i++)
    {
        if (minbuck[i] == INT_MAX and maxbuck[i] == INT_MIN)
            continue;
        ans = max(ans, minbuck[i] - max_prev);
        max_prev = maxbuck[i];
    }
    ans = max(ans, mx - max_prev);
    return ans;
}

// Method 2: using sorting TC=O(nlogn) SC=O(1)
int Solution::maximumGap(const vector<int> &b)
{
    vector<int> a(b);
    int n = a.size();
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, a[i + 1] - a[i]);
    }
    return ans;
}
