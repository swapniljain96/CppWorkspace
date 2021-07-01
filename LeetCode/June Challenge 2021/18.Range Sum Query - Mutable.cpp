// Given an integer array `nums`, handle multiple queries of the following types:

// 1. **Update** the value of an element in `nums`.
// 2. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

// Implement the `NumArray` class:

// - `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
// - `void update(int index, int val)` **Updates** the value of `nums[index]` to be `val`.
// - `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).
class NumArray
{
private:
    int n;
    vector<int> seg;

    int build(const vector<int> &a, int l, int r, int node)
    {
        int mid, lsum, rsum;
        if (l == r)
            return seg[node] = a[l];
        mid = (l + r) / 2;
        lsum = build(a, l, mid, 2 * node + 1);
        rsum = build(a, mid + 1, r, 2 * node + 2);
        return seg[node] = lsum + rsum;
    }

    int sumRange(int l, int r, int ss, int se, int node)
    {
        int lsum, rsum, mid;

        if (r < ss || l > se)
            return 0;
        if (l <= ss and se <= r)
            return seg[node];

        mid = (ss + se) / 2;
        lsum = sumRange(l, r, ss, mid, 2 * node + 1);
        rsum = sumRange(l, r, mid + 1, se, 2 * node + 2);
        return lsum + rsum;
    }

    int update(int index, int newValue, int ss, int se, int node)
    {
        int lsum, rsum, mid;

        if (index < ss || index > se)
            return seg[node];
        if (se == ss)
            return seg[node] = newValue;

        mid = (ss + se) / 2;
        lsum = update(index, newValue, ss, mid, 2 * node + 1);
        rsum = update(index, newValue, mid + 1, se, 2 * node + 2);
        return seg[node] = lsum + rsum;
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, n - 1, 0);
    }

    void update(int index, int val)
    {
        update(index, val, 0, n - 1, 0);
    }

    int sumRange(int left, int right)
    {
        return sumRange(left, right, 0, n - 1, 0);
    }
};
