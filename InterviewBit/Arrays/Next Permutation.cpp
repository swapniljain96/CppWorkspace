// Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

// If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.
vector<int> Solution::nextPermutation(vector<int> &a)
{
    int n = a.size();
    int sp = -1;
    for (int i = n - 1; i > 0; i--) // we have to find the first element from back where a[i]>a[i-1]
    {
        if (a[i] > a[i - 1]) // make this is swap index
        {
            sp = i;
            break;
        }
    }

    if (sp == -1) // if swap index is -1 means ur array is sorted in decreasing order just reverse the array
    {
        reverse(a.begin(), a.end());
    }
    else
    {
        int ind = sp;
        for (int i = sp + 1; i < n; i++) //if not then find number between that swap and array last. which is greater that a[swap-1] index
        {
            if (a[sp - 1] < a[i] && a[i] <= a[sp]) // and smaller then a[swap] then swap it with a[swap-1]
                ind = i;
        }
        swap(a[ind], a[sp - 1]);
        reverse(a.begin() + sp, a.end()); //here sort the array after swap index
    }
    return a;
}
