// Given an unsorted integer array, find the first missing positive integer.
// Example:
// Given [1,2,0] return 3,
// [3,4,-1,1] return 2,
// [-8, -7, -6] returns 1
// Your algorithm should run in O(n) time and use constant space.

int Solution::firstMissingPositive(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int k = 1;                  // here we initialse our default answer with -1 if array have all -ve number
    for (int i = 0; i < n; i++) //here we traverse the array from start
    {
        if (a[i] > 0) // we check condition if any number is greater than 0 means +ve
        {
            if (a[i] != k) // if our increasing counting break then return that number.
                break;
            k++;
        }
    }
    return k;
}
