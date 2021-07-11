/* You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
If so, return the integer. If not, return -1.
If there are multiple solutions, return any one.
Example :
Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times.  */

int Solution::repeatedNumber(const vector<int> &a)
{
    int n = a.size();
    int cnt1 = 0, cnt2 = 0;
    int m1 = INT_MAX, m2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && a[i] != m2)
        {
            m1 = a[i];
            cnt1++;
            continue;
        }
        else if (cnt2 == 0 && a[i] != m1)
        {
            m2 = a[i];
            cnt2++;
            continue;
        }
        if (a[i] == m1)
        {
            cnt1++;
        }
        else if (a[i] == m2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == m1)
            a1++;
        if (a[i] == m2)
            a2++;
    }
    if (a1 > n / 3)
    {
        return m1;
    }
    else if (a2 > n / 3)
    {
        return m2;
    }
    else
        return -1;
}
