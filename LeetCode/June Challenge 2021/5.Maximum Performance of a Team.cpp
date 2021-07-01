// You are given two integers `n` and `k` and two integer arrays `speed` and `efficiency` both of length `n`. There are `n` engineers numbered from `1` to `n`. `speed[i]` and `efficiency[i]` represent the speed and efficiency of the `ith` engineer respectively.

// Choose **at most** `k` different engineers out of the `n` engineers to form a team with the maximum **performance**.

// The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

// Return *the maximum performance of this team*. Since the answer can be a huge number, return it **modulo** `109 + 7`.
class Solution
{
public:
#define ll long long
#define MOD 1000000007
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        ll res = 0, tspeed = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        multiset<int> s;
        for (auto x : v)
        {
            tspeed += x.second;
            res = max(res, (x.first * tspeed));
            s.insert(x.second);
            if (s.size() >= k)
            {
                tspeed -= (*s.begin());
                s.erase(s.begin());
            }
        }
        return (int)(res % MOD);
    }
};