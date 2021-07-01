// Given a string `s` and an array of strings `words`, return *the number of* `words[i]` *that is a subsequence of* `s`.

// A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// - For example, `"ace"` is a subsequence of `"abcde"`.
// Method 1
class Solution
{
public:
    bool solve(string s, string w)
    {
        int j = 0;
        for (int i = 0; i < s.size() && j < w.size(); i++)
        {
            if (s[i] == w[j])
            {
                j++;
            }
        }
        return j == w.size();
    }
    int numMatchingSubseq(string s, vector<string> &w)
    {
        int ans = 0;
        unordered_map<string, bool> m;
        for (auto x : w)
        {
            if (m.find(x) != m.end())
            {
                if (m[x])
                    ans++;
            }
            else
            {
                bool flag = solve(s, x);
                m[x] = flag;
                if (flag)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Method 2
class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<int> index[26];
        for (int i = 0; i < s.size(); i++)
        {
            index[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for (string x : words)
        {
            int prevChar = -1; //means prev occurance of the chararter is at -1
            for (int i = 0; i < x.size(); i++)
            {
                auto itr = upper_bound(index[x[i] - 'a'].begin(), index[x[i] - 'a'].end(), prevChar);
                if (itr == index[x[i] - 'a'].end())
                {
                    goto h;
                }
                prevChar = *itr;
            }
            ans++;
        h:;
        }
        return ans;
    }
};