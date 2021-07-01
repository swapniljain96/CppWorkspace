// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
class Solution
{
public:
    void update(int i, vector<int> &BIT)
    {
        while (i <= BIT.size())
        {
            BIT[i]++;
            i += i & -i;         // here we perfrom the 3 steps at same time
        }                       // (1) 2's complement (2) AND with original number
    }                          //  (3) add to original number for updating we have to go to next

    int answer(int i, vector<int> &BIT)
    {
        int ans = 0;
        while (i > 0)
        {
            ans += BIT[i]; 
            i -= i & -i;         // here we perfrom the 3 steps at same time
        }                       // (1) 2's complement (2) AND with original number
        return ans;            //  (3) minus to original number for getting answer we have to goto parent
    }
    vector<int> countSmaller(vector<int> &a)
    {
        int n = a.size();
        vector<int> BIT(20005, 0);
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            a[i] += 10001;
        } // we are making every number positive bcoz it is worse to maitain -ve num

        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = answer(a[i] - 1, BIT);
            update(a[i], BIT);
        }
        return ans;
    }
};