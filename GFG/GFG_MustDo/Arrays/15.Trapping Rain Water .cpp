/* Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

Your Task:
You don'y need to read input or print anything. The task is to complete the function trappingWater() which takes arr and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
3 <= N <= 107
0 <= Ai <= 108 */

// Method 1:
class Solution
{
public:
    int trappingWater(int a[], int n)
    {
        int lmax[n], rmax[n];
        lmax[0] = a[0];
        rmax[n - 1] = a[n - 1];
        for (int i = 1; i < n; i++)
        {
            lmax[i] = max(lmax[i - 1], a[i]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rmax[i] = max(rmax[i + 1], a[i]);
        }

        int wat = 0;
        for (int i = 0; i < n; i++)
        {
            wat += min(lmax[i], rmax[i]) - a[i];
        }
        return wat;
    }
};

// Method 2:

class Solution
{
public:
    int trap(vector<int> &a)
    {
        int n = a.size();
        int l = 0, r = a.size() - 1;
        int water = 0, msfl = 0, msfr = 0;
        while (l < r)
        {
            msfl = max(msfl, a[l]);
            msfr = max(msfr, a[r]);
            if (a[l] > a[r])
            {
                water += min(msfl, msfr) - a[r];
                r--;
            }
            else
            {
                water += min(msfl, msfr) - a[l];
                l++;
            }
        }
        return water;
    }
};