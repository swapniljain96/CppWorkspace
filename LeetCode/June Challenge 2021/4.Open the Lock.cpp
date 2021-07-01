// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. The wheels can rotate freely and wrap around: for example we can turn `'9'` to be `'0'`, or `'0'` to be `'9'`. Each move consists of turning one wheel one slot.

// The lock initially starts at `'0000'`, a string representing the state of the 4 wheels.

// You are given a list of `deadends` dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

// Given a `target` representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        set<int> s;
        for (auto x : deadends)
            s.insert(stoi(x));

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<bool> vis(10000, false);
        vis[0] = true;
        while (!q.empty())
        {
            int v = q.front().first;
            int level = q.front().second;
            q.pop();
            if (s.count(v))
                continue;

            if (v == stoi(target))
                return level;
            string cur = "0000" + to_string(v);
            while (cur.size() > 4)
            {
                cur.erase(cur.begin());
            }
            for (int j = 0; j < 4; j++)
            {
                int num = cur[j] - '0';
                int next = num == 9 ? 0 : num + 1;
                int prev = num == 0 ? 9 : num - 1;
                string s1 = cur;
                string s2 = cur;
                s1[j] = '0' + next;
                s2[j] = '0' + prev;

                if (!vis[stoi(s1)])
                {
                    vis[stoi(s1)] = true;
                    q.push({stoi(s1), level + 1});
                }
                if (!vis[stoi(s2)])
                {
                    vis[stoi(s2)] = true;
                    q.push({stoi(s2), level + 1});
                }
            }
        }
        return -1;
    }
};