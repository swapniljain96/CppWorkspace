/* Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9] */

// Method 1: Using two pointers and resizing the resultating array.
// TC: O(m+n) SC: O(1)
void Solution::merge(vector<int> &a, vector<int> &b)
{
    int na = a.size();
    int nb = b.size();
    int i = na - 1, j = nb - 1, end = na + nb - 1;
    a.resize(na + nb);
    while (i >= 0 and j >= 0)
    {
        if (a[i] > b[j])
        {
            a[end--] = a[i--];
        }
        else
        {
            a[end--] = b[j--];
        }
    }
    while (j >= 0)
    {
        a[end--] = b[j--];
    }
}

// Method 2: Using extra space
// TC: O(m+n) SC: O(m+n)
void Solution::merge(vector<int> &a, vector<int> &b)
{
    int na = a.size();
    int nb = b.size();
    vector<int> v;
    int i = 0, j = 0;
    while (i < na and j < nb)
    {
        if (a[i] < b[j])
        {
            v.push_back(a[i]);
            i++;
        }
        else
        {
            v.push_back(b[j]);
            j++;
        }
    }
    while (i < na)
    {
        v.push_back(a[i]);
        i++;
    }
    while (j < nb)
    {
        v.push_back(b[j]);
        j++;
    }
    a = v;
}
