/* Problem Description
Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
**Problem Constraints**
1 <= |A| <= 100000
1 <= B <= 109
**Input Format**
First argument is array A.
Second argument is integer B.
**Output Format**
Return an integer, the answer to the problem.
**Example Input**
Input 1:
A = [1, 3, 5, 6]
B = 5
Input 2:
A = [1, 3, 5, 6]
B = 2
**Example Output**
Output 1:
 2
Output 2:
 1
**Example Explanation**
Explanation 1:
 5 is found at index 2.
Explanation 2:
2 will be inserted ar index 1. */

//Algo: problem boils down to finding the floor of the given number.

//Method 1: using lower_bound function.
int Solution::searchInsert(vector<int> &a, int x)
{
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

//Method 2: using binary function.
int Solution::searchInsert(vector<int> &a, int x)
{
    int l = 0, r = a.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (x > a[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
