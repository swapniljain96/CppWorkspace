// You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.

// Return `true` if you can make this square and `false` otherwise.
class Solution
{
public:
    bool visited(vector<int> &sides, int pos)
    {
        for (int i = 0; i < pos; i++)
        {
            if (sides[i] == sides[pos])
                return true;
        }
        return false;
    }
    bool dpRecur(vector<int> &a, vector<int> &sides, int target, int pos)
    {
        if (pos == a.size())
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        for (int i = 0; i < 4; i++)
        {
            if (sides[i] + a[pos] > target || visited(sides, i))
                continue;
            sides[i] += a[pos];
            if (dpRecur(a, sides, target, pos + 1))
                return true;
            sides[i] -= a[pos];
        }
        return false;
    }
    bool makesquare(vector<int> &a)
    {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        if (sum % 4 != 0 or n < 4)
            return false;
        sum /= 4;
        sort(a.rbegin(), a.rend());
        if (a[0] > sum) // we are checking only for 1st bcoz we already sort array in decreasing order
            return false;
        vector<int> sides(4, 0);
        return dpRecur(a, sides, sum, 0);
    }
};