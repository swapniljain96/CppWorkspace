/* Given two arrays X and Y of positive integers, find the number of pairs such that xy > yx (raised to power of) where x is an element from X and y is an element from Y.

Example 1:

Input: 
M = 3, X[] = [2 1 6] 
N = 2, Y[] = [1 5]
Output: 3
Explanation: 
The pairs which follow xy > yx are 
as such: 21 > 12,  25 > 52 and 61 > 16 .
Example 2:

Input: 
M = 4, X[] = [2 3 4 5]
N = 3, Y[] = [1 2 3]
Output: 5
Explanation: 
The pairs for the given input are 
21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 
51 > 15 .

Your Task:
This is a function problem. You only need to complete the function countPairs() that takes X, Y, M, N as parameters and returns the total number of pairs.

Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ M, N ≤ 105
1 ≤ X[i], Y[i] ≤ 103 */

class Solution
{
public:
    int getIndex(int y[], int n, int ele)
    {
        int l = 0;
        int h = n - 1;
        int ans = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (y[mid] > ele)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }

    long long countPairs(int x[], int y[], int m, int n)
    {
        sort(x, x + m);
        sort(y, y + n);
        long cnt = 0;
        int zeros = 0, one = 0, two = 0, three = 0, four = 0;
        for (int i = 0; i < n; i++)
        {
            if (y[i] == 0)
                zeros++;
            if (y[i] == 1)
                one++;
            if (y[i] == 2)
                two++;
            if (y[i] == 3)
                three++;
            if (y[i] == 4)
                four++;
        }
        for (int i = 0; i < m; i++)
        {
            if (x[i] == 0)
            {
                continue;
            }
            else if (x[i] == 1)
            {
                cnt = cnt + zeros;
            }
            else if (x[i] == 2)
            {
                int index = getIndex(y, n, 2);
                if (index != -1)
                {
                    cnt += n - index;
                }

                cnt -= three;
                cnt -= four;
                cnt += one + zeros;
            }
            else
            {
                int index = getIndex(y, n, x[i]);
                if (index != -1)
                {
                    cnt += n - index;
                }
                cnt += one + zeros;
                if (x[i] == 3)
                {
                    cnt += two;
                }
            }
        }
        return cnt;
    }
};