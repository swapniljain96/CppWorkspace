/* You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C.  */

// Method 1: using 3 pointers technique TC: O(n) SC: O(1)
//  See, you want to minimise abs(A[i]-B[j]) and so on, so think of bringing the individual diff as close to zero!
// If B[j] is both less than A[i] and C[k] then obviously we need to check the next B[j]
// since we want both abs(A[i]-B[j]) and abs(C[k]-B[j]) to get close to zero!

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int ans = INT_MAX;
    while (i < A.size() && j < B.size() && k < C.size())
    {
        ans = min(ans, max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])}));
        if (B[j] <= A[i] && B[j] <= C[k])
            j++;
        else if (C[k] <= B[j] && C[k] <= A[i])
            k++;
        else if (A[i] <= C[k] && A[i] <= B[j])
            i++;
    }
    return ans;
}

// Method 2: using 3 pointers technique TC: O(n) SC: O(1)

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0, j = 0, k = 0;
    int diff = INT_MAX;
    int mn = INT_MAX, mx = INT_MIN;
    while (i < A.size() && j < B.size() && k < C.size())
    {
        mx = max({A[i], B[j], C[k]});
        mn = min({A[i], B[j], C[k]});
        diff = min(diff, mx - mn);
        if (diff == 0)
            break;
        if (mn == A[i])
            i++;
        else if (mn == B[j])
            j++;
        else
            k++;
    }
    return diff;
}
