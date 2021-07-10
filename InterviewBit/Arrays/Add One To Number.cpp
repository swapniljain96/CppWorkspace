/* Given a non-negative number represented as an array of digits,
add 1 to the number ( increment the number represented by the digits ).
The digits are stored such that the most significant digit is at the head of the list.
Example:
If the vector has [1, 2, 3]
the returned vector should be [1, 2, 4]
as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit. */

vector<int> Solution::plusOne(vector<int> &a)
{
    int n = a.size();
    reverse(a.begin(), a.end());
    vector<int> v;
    int carry = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = a[i] + carry;
        v.push_back(curr % 10);
        carry = curr / 10;
    }
    if (carry == 1)
    {
        v.push_back(1);
    }
    while (v.back() == 0)
    {
        v.pop_back();
    }
    reverse(v.begin(), v.end());
    return v;
}
