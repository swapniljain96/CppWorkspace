/* Remove Element

Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

 Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1,
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity. */

// Algo: keep 2 pointers i,j; where i keep count of values that is not equal to B, traverse the array with j and if a[j] is not equal to value
// just copy the value into index i and increment i.

int Solution::removeElement(vector<int> &a, int B)
{
    int i = 0;
    for (int j = 0; j < a.size(); j++)
    {
        if (a[j] != B)
        {
            a[i++] = a[j];
        }
    }
    return i;
}
