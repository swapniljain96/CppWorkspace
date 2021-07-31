/* Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order. Duplicates may be there in the output list.

Example:

Input:
5
3 4 2 2 4
4
3 2 2 7

Output:
2 2 3

Explanation:
The first list is {3 4 2 2 4}, and the second list is {3 2 2 7}. 
The common elements in sorted order are {2 2 3}
User Task:
This is a function problem. You need to complete the function common_element that takes both the lists as parameters and returns a list of common elements.

Constraints:
1 <= n, m <= 105
1 <= Vi <= 105 */

class Solution
{
public:
    vector<int> common_element(vector<int> v1, vector<int> v2)
    {
        vector<int> v;
        map<int, int> m;
        for (int i = 0; i < v1.size(); i++)
        {
            m[v1[i]]++;
        }
        for (int i = 0; i < v2.size(); i++)
        {
            if (m[v2[i]])
            {
                v.push_back(v2[i]);
                m[v2[i]]--;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};