/*Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
Note that even though we want you to return the new length, make sure to change the original array as well in place
Do not allocate extra space for another array, you must do this in place with constant memory.
Example:
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].  */

// Method 1: assigning distinct values in the start of array
int Solution::removeDuplicates(vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[i] != a[j])
        {
            a[++i] = a[j];
        }
    }
    return i + 1;
}

// Method 2: using inbuilt erase and unique function
int Solution::removeDuplicates(vector<int> &a)
{
    a.erase(unique(a.begin(), a.end()), a.end());
    return a.size();
}
