// Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

// You must write an algorithm that runs in `O(n)` time.
class Solution
{
public:
    int longestConsecutive(vector<int> &a)
    {   unordered_map<int, int> m;
        int ans = 0;
        for (auto x : a)
            m[x]++;
        for (int i = 0; i < a.size(); i++)
        {   if (!m[a[i] - 1])
            {   int j = a[i];
                while (m[j])
                {
                    j++;
                }
                ans = max(ans, j - a[i]);
            }
        }
        return ans;
    }
};