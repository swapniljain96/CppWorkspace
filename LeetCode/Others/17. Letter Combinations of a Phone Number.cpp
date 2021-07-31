/* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']. */

// Method 1: Iterative
class Solution
{
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> result;
        result.push_back("");

        for (auto digit : digits)
        {
            vector<string> tmp;
            for (auto candidate : pad[digit - '0'])
            {
                for (auto s : result)
                {
                    tmp.push_back(s + candidate);
                }
            }
            result.swap(tmp);
        }
        return result;
    }
};

// Method 2: Naive Approach
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        int n = digits.size();
        vector<string> v[10];
        v[0] = {};
        v[1] = {};
        v[2] = {"a", "b", "c"};
        v[3] = {"d", "e", "f"};
        v[4] = {"i", "g", "h"};
        v[5] = {"j", "k", "l"};
        v[6] = {"m", "n", "o"};
        v[7] = {"p", "q", "r", "s"};
        v[8] = {"t", "u", "v"};
        v[9] = {"w", "x", "y", "z"};

        if (n == 0)
            return ans;

        if (n == 1)
        {
            for (int i = 0; i < v[digits[0] - '0'].size(); i++)
                ans.push_back(v[digits[0] - '0'][i]);
            return ans;
        }

        if (n == 2)
        {
            for (int i = 0; i < v[digits[0] - '0'].size(); i++)
                for (int j = 0; j < v[digits[1] - '0'].size(); j++)
                {
                    string tmp = v[digits[0] - '0'][i] + v[digits[1] - '0'][j];
                    ans.push_back(tmp);
                }
            return ans;
        }

        if (n == 3)
        {
            for (int i = 0; i < v[digits[0] - '0'].size(); i++)
                for (int j = 0; j < v[digits[1] - '0'].size(); j++)
                    for (int k = 0; k < v[digits[2] - '0'].size(); k++)
                    {
                        string tmp = v[digits[0] - '0'][i] + v[digits[1] - '0'][j] + v[digits[2] - '0'][k];
                        ans.push_back(tmp);
                    }
            return ans;
        }

        if (n == 4)
        {
            for (int i = 0; i < v[digits[0] - '0'].size(); i++)
                for (int j = 0; j < v[digits[1] - '0'].size(); j++)
                    for (int k = 0; k < v[digits[2] - '0'].size(); k++)
                        for (int l = 0; l < v[digits[3] - '0'].size(); l++)
                        {
                            string tmp = v[digits[0] - '0'][i] + v[digits[1] - '0'][j] + v[digits[2] - '0'][k] + v[digits[3] - '0'][l];
                            ans.push_back(tmp);
                        }
            return ans;
        }

        return ans;
    }
};