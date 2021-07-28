/* Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 <= |S| <= 2000 */

//Method 1: using stack
class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string S)
    {
        int n = S.size();
        S = S + '.';
        // cout<<"New S is:"<<S<<"\n";
        stack<char> st;
        string res = "";
        for (int i = 0; i < S.size(); i++)
        {
            string word = "";
            st.push(S[i]);
            if (S[i] == '.')
            {
                while (!st.empty())
                { //char ch;
                    //ch=st.top();
                    word = word + st.top();
                    st.pop();
                }
            }
            //   cout<<"Word is:"<<word<<"\n";
            res = res + word;
        }
        // cout<<"res:"<<res<<"\n";
        reverse(res.begin(), res.end());
        // cout<<"Reverse res:"<<res<<"\n";
        res.erase(res.begin() + n);
        // cout<<"Final res:"<<res<<"\n";
        return res;
    }
};

// Method 2: using substr
class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string S)
    {
        int n = S.size();
        int i = 0;
        string res = "";
        while (i < n)
        {
            int j = i + 1;
            while (j < n and S[j] != '.')
                j++;
            string sub = S.substr(i, j - i);
            res = sub + '.' + res;
            i = j + 1;
        }
        res.erase(res.begin() + n);
        return res;
    }
};