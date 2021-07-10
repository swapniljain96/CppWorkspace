/* Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
D means the next number is smaller, while I means the next number is greater.
Notes
Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :
Input 1:
n = 3
s = ID
Return: [1, 3, 2]   */

vector<int> Solution::findPerm(const string A, int n)
{   vector<int> v;
    int l = 1, r = n;                    //here we take start as l and end as r
    for (int i = 0; i < B - 1; i++)       
    {   if (A[i] == 'I')                 // if I encounter then push l and increment it
            v.push_back(l++); 
        else
            v.push_back(r--);           //else D encounter then push r and decrement it
    }
    v.push_back(l);
    return v;
}
