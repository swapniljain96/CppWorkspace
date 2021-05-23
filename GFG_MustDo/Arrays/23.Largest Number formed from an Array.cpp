// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	int static myComp(string x,string y)
	{ string xy=x.append(y);
	  string yx=y.append(x);
	  return xy.compare(yx)>0?1:0;
    }
	
	string printLargest(vector<string> &a) {
	   sort(a.begin(),a.end(),myComp);
	   string res="";
	   for(int i=0;i<a.size();i++)
	   { res+=a[i];}
	   return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends