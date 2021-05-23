// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int a[], int n) {
	    sort(a,a+n);
	    for(int i=0;i<n;i++)
	    { a[i]*=a[i]; }
	    for(int i=0;i<n;i++)
	    { for(int j=0;j<n;j++)
	        { if(binary_search(a,a+n,a[i]+a[j]))
	            { return true;}
	        }
	        
	    }
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends