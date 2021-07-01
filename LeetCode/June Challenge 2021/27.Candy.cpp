// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.
class Solution
{
public:
    int candy(vector<int> &a)
    {
        int n = a.size();
        vector<int> LR(n, 1), RL(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
            {
                LR[i] = 1 + LR[i - 1];
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
            {
                RL[i] = 1 + RL[i + 1];
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(LR[i], RL[i]);
        }
        return sum;
    }
};