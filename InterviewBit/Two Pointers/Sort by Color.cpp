/* Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2] */

// Method 1: Using 2 Pointers
// The solution requires the use of tracking 3 positions, the Low, Mid and High.
// We assume that the mid is the "Unknown" area that we must evaluate.
// If we encounter a 0, we know that it will be on the low end of the array, and if we encounter a 2, we know it will be on the high end of the array.
// To achieve this in one pass without preprocessing (counting), we simply traverse the unknown will generating the low and high ends.
// TC:O(n) SC:O(1)
void Solution::sortColors(vector<int> &a)
{
    int l = 0, m = 0, r = a.size() - 1;
    while (m <= r)
    {
        if (a[m] == 0)
        {
            swap(a[l], a[m]);
            l++;
            m++;
        }
        else if (a[m] == 1)
        {
            m++;
        }
        else
        {
            swap(a[m], a[r]);
            r--;
        }
    }
}

// Method 2: Using sorting
// TC:O(n log n) SC:O(1)
void Solution::sortColors(vector<int> &a)
{
    sort(a.begin(), a.end());
}
