/* Sometimes people repeat letters to represent extra feeling. For example:

"hello" -> "heeellooo"
"hi" -> "hiiii"
In these strings like "heeellooo", we have groups of adjacent letters that are all the same: "h", "eee", "ll", "ooo".

You are given a string s and an array of query strings words. A query word is stretchy if it can be made to be equal to s by any number of applications of the following extension operation: choose a group consisting of characters c, and add some number of characters c to the group so that the size of the group is three or more.

For example, starting with "hello", we could do an extension on the group "o" to get "hellooo", but we cannot get "helloo" since the group "oo" has a size less than three. Also, we could do another extension like "ll" -> "lllll" to get "helllllooo". If s = "helllllooo", then the query word "hello" would be stretchy because of these two extension operations: query = "hello" -> "hellooo" -> "helllllooo" = s.
Return the number of query strings that are stretchy.

Example 1:

Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
Example 2:

Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
Output: 3

Constraints:

1 <= s.length, words.length <= 100
1 <= words[i].length <= 100
s and words[i] consist of lowercase letters. */

// Method 1:
class Solution
{
public:
    bool solve(string s, string word)
    {
        int i = 0, j = 0;
        if (word.length() > s.length())
            return false;
        while (i < s.length() and j < word.length())
        {
            if (s[i] != word[j])
                return false;
            i++, j++;
            int cnt1 = 1, cnt2 = 1;
            while (i < s.length() and s[i] == s[i - 1])
                cnt1++, i++;
            while (j < word.length() and word[j] == word[j - 1])
                cnt2++, j++;
            if (cnt2 > cnt1)
                return false;
            if (cnt1 < 3)
                if (cnt1 != cnt2)
                    return false;
        }
        if (i == s.length() and j == word.length())
            return true;
        return false;
    }

    int expressiveWords(string s, vector<string> &words)
    {
        int ans = 0;
        for (auto word : words)
            ans = solve(s, word) ? ans + 1 : ans;
        return ans;
    }
};

// Method 2:

class Solution
{
public:
    string minLength(string s)
    {
        int l = 0, r = 0, n = s.size();
        string res;
        while (l < n)
        {
            if (s[l] != s[r] or r == n)
            {
                res += s[l];
                res += '0' + (r - l);
                l = r;
            }
            else
            {
                r++;
            }
        }

        return res;
    }

    int expressiveWords(string S, vector<string> &words)
    {
        S = minLength(S);
        int ans = 0, n = S.size();
        cout << S << endl;

        for (auto &word : words)
        {
            word = minLength(word);
            if (word.size() == S.size())
            {
                int flag = 0;
                for (int i = 1; i < n; i += 2)
                {
                    if (word[i - 1] != S[i - 1] or !(word[i] == S[i] or (S[i] >= '3' and word[i] < S[i])))
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    ans++;
            }
        }

        return ans;
    }
};