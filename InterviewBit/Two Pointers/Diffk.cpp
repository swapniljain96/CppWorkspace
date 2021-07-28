/* Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example: Input : 
    A : [1 3 5] 
    k : 4
Output : YES as 5 - 1 = 4 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem */

// Method 1: Using binary search for finding if there is any element like a[i]+k in the array bcoz sorted array is already present.
// TC: O(n) SC: O(1)
int Solution::diffPossible(vector<int> &a, int k)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (binary_search(a.begin() + i + 1, a.end(), a[i] + k))
        {
            return 1;
        }
    }
    return 0;
}

// Method 2(a): Using two pointers.
// TC: O(n) SC: O(1)
int Solution::diffPossible(vector<int> &a, int k)
{
    int i = 0, j = a.size() - 1;
    while (i < j)
    {
        if (a[i] + k == a[j])
        {
            return 1;
        }
        else if (a[i] + k < a[j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

// Method 2(b): Using two pointers.
// TC: O(n) SC: O(1)
int Solution::diffPossible(vector<int> &a, int k)
{
    int i = 0, j = 1;
    while (i < a.size() and j < a.size())
    {
        if (i != j and a[j] - a[i] == k)
        {
            return 1;
        }
        else if (a[j] - a[i] < k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
