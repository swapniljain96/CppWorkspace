/* Given a string S. The task is to print all permutations of a given string.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

 

Constraints:
1 <= length of string <= 5 */

class Solution
{
public:
    vector<string> res;
    void permute(string a, int l, int r)
    { // Base case
        if (l == r)
            res.push_back(a);
        else
        {
            // Permutations made
            for (int i = l; i <= r; i++)
            {

                // Swapping done
                swap(a[l], a[i]);

                // Recursion called
                permute(a, l + 1, r);

                //backtrack
                swap(a[l], a[i]);
            }
        }
    }
    vector<string> find_permutation(string S)
    {
        permute(S, 0, S.size() - 1);
        sort(res.begin(), res.end());
        return res;
    }
};