/* Given a non-negative number represented as a list of digits, add 1 to the number (increment the number represented by the digits). The digits are stored such that the most significant digit is first element of array.
Example 1:
Input: 
N = 3
arr[] = {1, 2, 4}
Output: 
1 2 5
Explanation:
124+1 = 125, and so the Output
Example 2:
Input: 
N = 3
arr[] = {9,9,9}
Output: 
1 0 0 0
Explanation:
999+1 = 1000, and so the output */
class Solution
{
public:
    vector<int> increment(vector<int> a, int n)
    {
        vector<int> v;
        reverse(a.begin(), a.end());
        int c = 1;
        for (int i = 0; i < a.size(); i++)
        {
            int num = a[i] + c;
            v.push_back(num % 10);
            c = num / 10;
        }
        if (c == 1)
        {
            v.push_back(1);
        }

        //    while(v.back() == 0)  //if we have given 0 in the front of the array
        //    {
        //     v.pop_back();
        //     }
        reverse(v.begin(), v.end());
        return v;
    }
};