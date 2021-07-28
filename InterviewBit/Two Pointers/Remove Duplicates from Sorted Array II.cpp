/* Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,
Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2]. */

// Method 1(a): Two Pointer Approach , start i from 2 and check if a[i] != a[in-2] then copy the elements from i to in-2.
// TC=O(n) SC=O(1)
int Solution::removeDuplicates(vector<int> &a)
{
    if (a.size() < 3)
        return a.size();
    int in = 2;
    for (int i = 2; i < a.size(); i++)
    {
        if (a[i] != a[in - 2])
        {
            a[in++] = a[i];
        }
    }
    return in;
}
// Method 1(b): Two Pointer Approach.
// TC=O(n) SC=O(1)
int Solution::removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (auto e : nums)
    {
        if (i < 2 || e > nums[i - 2])
            nums[i++] = e;
    }
    return i;
}

// Method 2: here we use map to count the frequencies of the elements and based on which we put into the result vector.
// TC=O(n) SC=O(n)
int Solution::removeDuplicates(vector<int> &a)
{
    unordered_map<int, int> m;
    int i = 0, j = 0;
    for (int x : a)
    {
        m[x]++;
        if (m[x] < 3)
        {
            a[i] = a[j];
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i;
}
