// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res = "";
        for (char x : s)
        {
            if (res.empty())
            {
                res += x;
            }
            else
            {
                if (res.back() == x)
                {
                    res.pop_back();
                }
                else
                {
                    res += x;
                }
            }
        }
        return res;
    }
};