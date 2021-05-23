// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int a[], int n) {
	  bool flag=true;            //here we maintain flag to find which operatio we have to perform < or >
	  for(int i=0;i<n-1;i++)     // we will initial operation by seeing the question  
	  { if(flag)
	      { if(a[i]>a[i+1])
	          { swap(a[i],a[i+1]); }
	      }
	    else
	    { if(a[i]<a[i+1])
	          { swap(a[i],a[i+1]); }
	    }  
	    flag=!flag;
	  }
	}
	
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends