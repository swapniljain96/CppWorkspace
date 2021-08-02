/* Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.

Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.

Output Format

Return a sorted array of numbers.
Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are present in atleast 2 out of 3 lists. */

// Algo: Here we are using a set corresding every element in the array and traverse all 3 array and inserting the set number,
// in which corresponding to their key and if we occur size of set is more than 1 means that element is present in atleast 2 array.
// so we add it in our final vector.
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    unordered_map<int, set<int>> m;
    for (int x : A)
        m[x].insert(1);
    for (int x : B)
        m[x].insert(2);
    for (int x : C)
        m[x].insert(3);

    vector<int> v;
    for (auto x : m)
    {
        if (x.second.size() > 1)
            v.push_back(x.first);
    }
    sort(begin(v), end(v));
    return v;
}
